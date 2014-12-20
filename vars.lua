local vars = {}

function vars:add(type, name)
	table.insert(self.list, {
		type = type,
		name = name
	})
end

function vars:print()
	print(self)
end

function vars:init()
	self.list = {}
	return self
end

return vars
