#! /nfs/zfs-student-5/users/2013/adebray/.brew/bin/lua

-- Lua implementation of PHP scandir function
function scandir(directory)
	local i = 0
	local t = {}
	local popen = io.popen
	for filename in popen('ls -a "'..directory..'"'):lines() do
		i = i + 1
		t[i] = filename
	end
	return t
end

function loaddir(inc, src)
	incFolder = io.open("./inc")
	srcFolder = io.open("./src")

	if (incFolder == nil or srcFolder == nil) then
		print('No ./inc or ./src folder'); os.exit()
		os.exit();
	end
	inc_str, inc_msg, inc_err = incFolder:read("*a")
	src_str, src_msg, src_err = srcFolder:read("*a")

	if (inc_err ~= 21 or src_err ~= 21) then
		print('No ./inc or ./src folder'); os.exit()
	else
		incFolder:close()
		srcFolder:close()
	end
end

headers = {}

function headers:convert()
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

function headers:print()
	print("self.list: ")
	for k,v in pairs(self.list) do
		print(v)
	end
	print("self.content: ")
	for k,v in pairs(self.content) do
		print(inspect(v))
	end
end

function headers:init(incFolder)
	self.folder = incFolder
	self.list = scandir(inc)
	self.content = {}
	return self;
end

inc = "./inc"
src = "./src"

loaddir(inc, src)
headers:init(inc)
headers:convert()

headers:print()
