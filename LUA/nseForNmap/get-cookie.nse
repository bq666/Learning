-- Head
local shortport = require "shortport"
local http = require "http"
local stdnse = require "stdnse"

description = [[
Connect to website and get's any cookies returned by the server
]]
categories = { "safe" }

-- Rule
portrule = shortport.http

-- Action
action = function(host, port)
	local path = nmap.registry.args.path
	if(path == nil) then
		path = '/'
	end
	
	local response = http.get(host, port, path)
	local cookiejar = {}
	for key, cookie in pairs(response.cookies) do
		table.insert(cookiejar, "Cookie: name =" .. cookie.name .. ": value =" .. cookie.value)
	end

	-- print("My test")
	return stdnse.format_output(true, cookiejar)

end
