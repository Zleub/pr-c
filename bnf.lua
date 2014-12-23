local bnf = {}

function get_toplevel(line, var)
	local i = 1
	local pil = {}

	local open = 0
	while i <= #line do
		if line:sub(i, i) == '['
			and line:sub(i - 1, i - 1) ~= '"'
			and line:sub(i + 1, i + 1) ~= '"'
			and line:sub(i - 1, i - 1) ~= "'"
			and line:sub(i + 1, i + 1) ~= "'"
				then open = open + 1 end
		if line:sub(i, i) == ']'
			and line:sub(i - 1, i - 1) ~= '"'
			and line:sub(i + 1, i + 1) ~= '"'
			and line:sub(i - 1, i - 1) ~= "'"
			and line:sub(i + 1, i + 1) ~= "'"
				then open = open - 1 end
		if line:sub(i, i) == '{'
			and line:sub(i - 1, i - 1) ~= '"'
			and line:sub(i + 1, i + 1) ~= '"'
			and line:sub(i - 1, i - 1) ~= "'"
			and line:sub(i + 1, i + 1) ~= "'"
				then open = open + 1 end
		if line:sub(i, i) == '}'
			and line:sub(i - 1, i - 1) ~= '"'
			and line:sub(i + 1, i + 1) ~= '"'
			and line:sub(i - 1, i - 1) ~= "'"
			and line:sub(i + 1, i + 1) ~= "'"
				then open = open - 1 end
		if line:sub(i, i) == '('
			and line:sub(i - 1, i - 1) ~= '"'
			and line:sub(i + 1, i + 1) ~= '"'
			and line:sub(i - 1, i - 1) ~= "'"
			and line:sub(i + 1, i + 1) ~= "'"
				then open = open + 1 end
		if line:sub(i, i) == ')'
			and line:sub(i - 1, i - 1) ~= '"'
			and line:sub(i + 1, i + 1) ~= '"'
			and line:sub(i - 1, i - 1) ~= "'"
			and line:sub(i + 1, i + 1) ~= "'"
				then open = open - 1 end
		if line:sub(i, i) == '"'
			and line:sub(i - 1, i - 1) ~= '"'
			and line:sub(i + 1, i + 1) ~= '"'
			and line:sub(i - 1, i - 1) ~= "'"
			and line:sub(i + 1, i + 1) ~= "'"
				then open = open + 1 end
		if line:sub(i, i) == '"'
			and line:sub(i - 1, i - 1) ~= '"'
			and line:sub(i + 1, i + 1) ~= '"'
			and line:sub(i - 1, i - 1) ~= "'"
			and line:sub(i + 1, i + 1) ~= "'"
				then open = open - 1 end
		if line:sub(i, i) == "'"
			and line:sub(i - 1, i - 1) ~= '"'
			and line:sub(i + 1, i + 1) ~= '"'
			and line:sub(i - 1, i - 1) ~= "'"
			and line:sub(i + 1, i + 1) ~= "'"
				then open = open + 1 end
		if line:sub(i, i) == "'"
			and line:sub(i - 1, i - 1) ~= '"'
			and line:sub(i + 1, i + 1) ~= '"'
			and line:sub(i - 1, i - 1) ~= "'"
			and line:sub(i + 1, i + 1) ~= "'"
				then open = open - 1 end
		if line:sub(i, i) == var
			and line:sub(i - 1, i - 1) ~= '"'
			and line:sub(i + 1, i + 1) ~= '"'
			and line:sub(i - 1, i - 1) ~= "'"
			and line:sub(i + 1, i + 1) ~= "'"
				and open == 0 then table.insert(pil, {i, var}) end
		-- if line:sub(i, i) == '|'
		-- 	and line:sub(i - 1, i - 1) ~= '"'
		-- 	and line:sub(i + 1, i + 1) ~= '"'
		-- 	and line:sub(i - 1, i - 1) ~= "'"
		-- 	and line:sub(i + 1, i + 1) ~= "'"
		-- 		and open == 0 then table.insert(pil, {i, "|"}) end
		if line:sub(i, i) == ';'
			and line:sub(i - 1, i - 1) ~= '"'
			and line:sub(i + 1, i + 1) ~= '"'
			and line:sub(i - 1, i - 1) ~= "'"
			and line:sub(i + 1, i + 1) ~= "'"
				and open == 0 then table.insert(pil, {i, ";"}) end
		i = i + 1
	end
	return pil
end

function bnf:newdef(line)
	local tab = {}
	local name = string.match(line, "^%s*(%w+)%s*=")
	local l = string.match(line, "=(.+)")

	print("l: <"..l..">")
	pil = get_toplevel(l, '|')

	local i = 1
	local j = 1

	while i <= #pil do
		print(l:sub(j, pil[i][1]))
		j = pil[i][1]
		i = i + 1
	end


	-- test = string.gmatch(l, "([^,;]+)%s*[,;]")

	-- for val in test do print(val) end

	return {
		name = name,
		tab = tab
	}
end

function bnf:load(file)
	local line = io.read()
	while line do
		while not string.match(line, ";") do
			local tmp = io.read()
			if not tmp then
				print("End of file - Parsing Error")
				os.exit()
			end
			line = line..tmp
		end
		table.insert(self.defs, self:newdef(line))
		line = io.read()
	end
end

function bnf:init(file)
	self.defs = {}

	io.input(file)
	self:load(ifile)
	print(inspect(self))
end

bnf:init("test.bnf")
