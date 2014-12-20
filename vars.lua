local vars = {}

function vars:add(name)
	table.insert({
		name = name
	})
end

function vars:print()
	print("hello world")
end

function vars:init()
	self.list = {}
	return self
end

return vars
