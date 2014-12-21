local structs = {}

function structs:add(header, name, linedef)
	table.insert(self.list, {
		header = header,
		name = name,
		linedef = linedef,
		typedef = 0,
		vars = dofile("vars.lua"):init(),
		write_new = function (self, file)
			for k,v in pairs(self.vars.list) do
				if v.pointer == 1 then
					if string.match(v.name, "*") then
						file:write("\tnew->"..string.match(v.name, "*(.+)").." = NULL;\n")
					else
						file:write("\tnew->"..v.name.." = NULL;\n")
					end
				elseif v.fpointer == 1 then
					file:write("\tnew->"..string.match(v.name, "%(*(.+)%)%s*%(.+%)").." = NULL;\n")
				else
					file:write("\tnew->"..v.name.." = 0;\n")
				end
			end
		end
	})
end

function structs:print()
	print(inspect(self))
end

function structs:init(srcFolder)
	self.list = {}
	return self
end

return structs
