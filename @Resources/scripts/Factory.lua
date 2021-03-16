-- @author juh9870
-- Based on script made by undefinist / www.undefinist.com
-- Structure of Script Measure:
---- IncFile=
---- Number=
---- Delayed=
---- where N is an ordered number from 0
-- Use //...// to declare repeating block
---- For example, //[Measure%%]// will repeat "[Measure%%]" specified amount of times.
---- Block can be multiline
---- No nesting repeat block
------ "//I repeat N time // and I repeat N^2 times// cool, right?//" won't work
------ it will repeat only "I repeat N time " and " cool, right?" sections
-- Use %% to substitute it as the iteration number (which is specified by the Number option)
---- For example, if you specify 10, it will repeat each repeating block 10 times and replace the first repeated section's %%
---- with 0, the second repeated section's %% with 1, etc...
-- Wrap any formulas you want to parse in {} that otherwise RM would treat as a string
---- For example, [Measure{%%+1}] will have this script parse it for you

local Number=0;

function Initialize()
    local delay = SELF:GetNumberOption("Delayed")
    if delay~=0 then return end

	Number = SELF:GetNumberOption("Number")
    -- print(Number)
    run(Number)
end

function Run(num)
    -- print("Creating "..num)
    Number=num
	local sectionName = SELF:GetOption("SectionName")
    local incFile = SELF:GetOption("IncFile")

    local templateFile = io.open(SKIN:MakePathAbsolute(incFile..".template"), "r")
    local template=templateFile:read("*all")
    templateFile:close()

	local file = io.open(SKIN:MakePathAbsolute(incFile), "w")
	
    local result = template:gsub("//(.-)//", doRepl)

	file:write(result)
	file:close()
end

-- does duplication
function doRepl(value,num)
    local t = {}
    
	for i = 0, Number-1 do
		table.insert(t, (doSub(value, i)))
	end
    return table.concat(t, "")
end

-- does all the substitution!
function doSub(value, i)
    return value:gsub("%%%%", i):gsub("{.-}", parseFormula)
end

-- sub to remove {the curly braces}, then add (parentheses), then parse it
function parseFormula(formula)
    -- print(SKIN:ReplaceVariables("#Amount#"))
	return SKIN:ParseFormula("(" .. SKIN:ReplaceVariables(formula:sub(2, -2)) .. ")")
end