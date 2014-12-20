local structs = {}

function structs:add(header, name, linedef)
	table.insert(self.list, {
		header = header,
		name = name,
		linedef = linedef,
		typedef = 0,
		vars = dofile("vars.lua")
	})
end

function structs:print()
	print("structs:print: ")
	print("self.list: ")
	for k,v in pairs(self.list) do
		print(inspect(v))
	end
	print("")
end

function structs:init(srcFolder)
	self.list = {}
	return self
end

return structs
