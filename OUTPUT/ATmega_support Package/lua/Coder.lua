local Coder = { }
--local Blocks = { }
local arduino = require("arduino")
---local prescale = maths.prescale()
--local count = maths.count()

copy_file = function (src, dest, subs)
  local file = io.open(src, "rb")
  local src_content = file:read("*all")
	src_content = string.gsub( src_content, "\r", "")
  io.close(file)
  local dest_content

  file = io.open(dest, "rb")
  if(file == nil) then
    dest_content = nil
  else
    dest_content = file:read("*all")
    io.close(file)
  end



  if subs ~= nil then
  	for _,v in pairs(subs) do
  		local before = v["before"]
  		local after = v["after"]
  		src_content = string.gsub( src_content, before, after)
	end
  end

  if not (src_content == dest_content) then
    local file = io.open(dest, "w")
    io.output(file)
    io.write(src_content)
    file.close()
  end
end


local Registry = {
  NumDigitalBlocks = 0
}

function Coder.RegisterDigitalBlock()
  local ret = Registry.NumDigitalBlocks
  Registry.NumDigitalBlocks = ret+1
  return ret
end

--tostring(digiBlocks)
--Coder.RegisterDigitalBlock = RegisterDigitalBlock


function Coder.Initialize()
  local Resources = ResourceList:new()
  local Include = {}
  local Declarations = {}
  local PreInitCode = {}
  local PostInitCode = {}
  local TerminateCode = {}

  local dummy = print -- dummy access to global environment ("attempt to call a table value" workaround)

  Resources:add("GPIO", 0, 199)


  return {
     Declarations = Declarations,
     PreInitCode = PreInitCode,
     PostInitCode = PostInitCode,
     TerminateCode = TerminateCode,
     Include = Include,
     Resources = Resources
  }
end


function Coder.Finalize()
  local Include = {}
  local Declarations = {}
  local PreInitCode = {}
  local PostInitCode = {}
  local TerminateCode = {}

  local digiBlocks = tostring(Coder.RegisterDigitalBlock())
  local assert = settings(digiBlocks)
  if assert ~= false then return assert end

  local dict = {}
  table.insert(dict, {before = "|>BASE_NAME<|", after = Target.Variables.BASE_NAME})
  table.insert(dict, {before = "|>INSTALL_DIR<|", after = Target.Variables.installDir})
  copy_file(Target.Variables.TARGET_ROOT .. "/templates/install.mk", Target.Variables.BUILD_ROOT .. "/" .. Target.Variables.BASE_NAME .. ".mk", dict)


  return {
     Declarations = Declarations,
     PreInitCode = PreInitCode,
     PostInitCode = PostInitCode,
     TerminateCode = TerminateCode,
     Include = Include,
     Resources = Resources
  }
end

return Coder