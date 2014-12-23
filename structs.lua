local structs = {}

function structs:add(header, name, linedef)
	table.insert(self.list, {
		structs = self,
		header = header,
		name = name,
		linedef = linedef,
		typedef = 0,
		vars = dofile("vars.lua"):init(self),
		write_new = function (self, file)
			for k,v in pairs(self.vars.list) do
				-- print(inspect(v))
				if v.pointer == 1 and v.fpointer == 0 and v.t == 0 then
					if string.match(v.name, "*") then
						local name = string.match(v.name, "*(.+)")
						file:write("\tnew->"..name.." = NULL;\n")
					else
						file:write("\tnew->"..v.name.." = NULL;\n")
					end
				elseif v.pointer == 1 and v.t == 1 then
					local name = string.match(v.name, "*(.+)%[")
					print(self.header, v.name, name)
					local size = string.match(v.name, ".+%[(.+)%]")
					file:write("\tbzero((void*)(&new->"..name.."), sizeof("..v.type.."*) * "..size..");\n")
				elseif v.t == 1 and v.fpointer == 0 then
					local name = string.match(v.name, "(.+)%[")
					local size = string.match(v.name, ".+%[(.+)%]")
					file:write("\tbzero((void*)(&new->"..name.."), sizeof("..v.type..") * "..size..");\n")
				elseif v.fpointer == 1 then
					local name = string.match(v.name, "%(*([%w|_]+)%)%s*%(.+%)")
					print(self.header, v.name, name)
					file:write("\tnew->"..name.." = NULL;\n")
				elseif v.s == 1 then
					file:write("\tbzero((void*)(&new->"..v.name.."), sizeof("..v.type.."));\n")
				else
					file:write("\tnew->"..v.name.." = 0;\n")
				end
			end
		end
	})
end

function structs:is_typedef(type)
	for k,v in pairs(self.list) do
		if v.typedname == type then
			return true
		end
	end
	return false
end


function structs:print()
	print(inspect(self))
end

function structs:init(srcFolder)
	self.list = {}
	return self
end

return structs
