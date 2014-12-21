local vars = {}

function vars:add(type, name)
	local p = 0
	if string.match(type, "*") or string.match(name, "*") then p = 1 end

	local fp = 0
	if string.match(name, "%(.+%)%s*%(.+%)") then ft = 1 end
	table.insert(self.list, {
		type = type,
		name = name,
		pointer = p,
		fpointer = fp
	})
end

function vars:print()
	print(inspect(self))
end

function vars:init()
	self.list = {}
	return self
end

return vars
