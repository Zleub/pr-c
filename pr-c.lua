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
	incFolder = io.open(inc)
	srcFolder = io.open(src)

	if (incFolder == nil or srcFolder == nil) then
		print('No '..inc..' or '..src..' folder'); os.exit()
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

function trim(s)
  return (s:gsub("^%s*(.-)%s*$", "%1"))
end

inc = "./inc"
src = "./_src"

loaddir(inc, src)

if arg[1] then
	headers = require 'headers':init(inc, src, arg[1])
else
	headers = require 'headers':init(inc, src)
end

-- headers.structs:print()
