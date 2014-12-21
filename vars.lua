local vars = {}

function vars:add(type, name)
	local p = 0
	if string.match(type, "*") or string.match(name, "*") then p = 1 end

	local t = 0
	if string.match(name, "%[.+%]") then t = 1 end

	local fp = 0
	if string.match(name, "%(.+%)%s*%(.+%)") then fp = 1 end

	local s = 0
	if string.match(type, "struct") then s = 1 end
	if self.struct:is_typedef(type) then s = 1 end

	table.insert(self.list, {
		type = type,
		name = name,
		pointer = p,
		fpointer = fp,
		t = t,
		s = s
	})
end

function vars:print()
	print(inspect(self))
end

function vars:init(struct)
	self.struct = struct
	self.list = {}
	return self
end

return vars
