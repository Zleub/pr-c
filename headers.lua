local headers = {}

function headers:read()
	for k,v in pairs(self.list) do
		if v ~= "." and v ~= ".." then
			self.content[v] = {}
			local f = io.open(self.folder.."/"..v)
			for line in f:lines() do
				table.insert(self.content[v], line)
			end
		end
	end
end

function headers:convert()
	local struct_match = "struct%s+([A-z0-9]+)%s*[|{]?$"

	for k,v in pairs(self.content) do
		print(k, v)
		for key, val in pairs(v) do
			local name = string.match(val, struct_match)
			print(name, k, key)
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

function headers:print()
	print("headers:print: ")
	print("self.list: ")
	for k,v in pairs(self.list) do
		print(v)
	end
	print("")
	-- print("self.content: ")
	-- for k,v in pairs(self.content) do
	-- 	print(k)
	-- 	for key, val in pairs(v) do
	-- 		print(val)
	-- 	end
	-- end

	self.structs:print()
end

function headers:init(incFolder)
	self.structs = require 'structs':init(src)

	self.folder = incFolder
	self.list = scandir(inc)
	self.content = {}

	self:read()
	self:convert()
	self:fill_structs()
	return self;
end

return headers
