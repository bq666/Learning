kata = {}
function kata.firstLua(a,b,c)
    if b >= c then
        return a .. " " .. a * b .." Lua"
    else
        return a .. " " .. a * b .. " Codewars"
    end
end

print(kata.firstLua(1,2,3))
print(kata.firstLua(3,2,1))


return kata