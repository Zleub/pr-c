local headers = {}

function headers:read()
	if self.file then
		self.content[self.file] = {}
		local f = io.open(self.file)
		for line in f:lines() do
			table.insert(self.content[self.file], line)
		end
		return
	end

	for k,v in pairs(self.list) do
		if v ~= "." and v ~= ".." then
			self.content[v] = {}
			local f = io.open(self.incfolder.."/"..v)
			for line in f:lines() do
				table.insert(self.content[v], line)
			end
		end
	end
end

function headers:convert()
	local struct_match = "struct%s+([A-z0-9]+)%s*[|{]?$"

	for k,v in pairs(self.content) do
		for key, val in pairs(v) do
			local name = string.match(val, struct_match)
			local header = k
			local linedef = key
			if name then
				self.structs:add(header, name, linedef)
			end
		end
	end
end

function matchvar(line)
	local type, name = string.match(line, "^%s*([%w|%s|_]+)%s+(.+);.*$")
	if type and name then
		type = trim(type)
		name = trim(name)
		if string.match(type, ";") then
			print("I have a really nice issue here")
		elseif string.match(name, ";") then
			name = string.match(name, "(.+);.*")
		end
		return type, name
	end
end

function headers:fill_structs()
	for index, struct in pairs(self.structs.list) do
		local i =  struct.linedef
		local j = 1
		-- print(inspect(self.content, {depth=1}))
		while not string.match(self.content[struct.header][i], "}") do
			if j == 1 then
				if string.match(self.content[struct.header][i], "typedef") then
					struct.typedef = 1
				end
			else
				local type, name = matchvar(self.content[struct.header][i])
				if type and name then struct.vars:add(type, name) end
			end
			j = j + 1
			i = i + 1
		end
		if struct.typedef == 1 then
			struct.typedname = string.match(self.content[struct.header][i], "}%s*([A-z0-9]+)%s*;")
		end
	end
end

function write_manage_struct(file, struct)
	file:write("struct "..struct.name.."\t*manage_"..struct.name.."(int macro)\n")
	file:write("{\n")
	file:write("\tstatic struct "..struct.name.."\t*current;\n")
	file:write("\n")
	file:write("\tif (macro == NEW)\n")
	file:write("\t\tcurrent = new_"..struct.name.."();\n")
	file:write("\telse if (macro == GET)\n")
	file:write("\t\treturn (current);\n")
	file:write("\telse\n")
	file:write("\t\twrite(1, \"manage_"..struct.name..": no decent macro\\n\", "..(#struct.name + 7 + 18)..");\n")
	file:write("\treturn (NULL);\n")
	file:write("}\n")
	file:write("")
end

function write_new_struct(file, struct)
	file:write("struct "..struct.name.."\t*new_"..struct.name.."(void)\n")
	file:write("{\n")
	file:write("\tstruct "..struct.name.."\t*new;\n")
	file:write("\n")
	file:write("\tif (!(new = (struct "..struct.name.."*)malloc(sizeof(struct "..struct.name.."))))\n")
	file:write("\t\treturn (NULL);\n")
	struct:write_new(file)
	file:write("\treturn (new);\n")
	file:write("}\n")
	file:write("\n")
end

function headers:write_structs()
	for k,struct in pairs(self.structs.list) do
		local file = io.open(self.srcFolder.."/"..struct.name..".c", "w")
		file:write("#include <stdlib.h>\n")
		file:write("#include <string.h>\n")
		file:write("#include <"..struct.header..">\n")
		file:write("\nenum e_macro\n")
		file:write("{\n")
		file:write("\tNEW,\n")
		file:write("\tGET\n")
		file:write("};\n")
		file:write("\n")
		write_new_struct(file, struct)
		write_manage_struct(file, struct)
	end
end

function headers:print()
	print(inspect(self))
end

function headers:init(incFolder, srcFolder, file)
	self.structs = require 'structs':init(srcFoler)

	self.incfolder = incFolder
	self.srcFolder = srcFolder
	self.list = scandir(inc)
	if file then
		self.file = file end
	self.content = {}

	self:read()
	self:convert()
	self:fill_structs()
	self:write_structs()
	return self;
end

return headers
