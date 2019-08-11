-- The Head
local shortport = require "shortport"

description = [[
The NSE version of Hello World!
]]

categories = { "safe" }

-- The Rule
portrule = shortport.http


-- The Action
action = function(host, port)
	local myoutput = "Hello World!"
	
	return myoutput
end
