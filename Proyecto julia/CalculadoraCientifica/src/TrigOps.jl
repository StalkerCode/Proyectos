module TrigOps

export r_sin, r_cos, r_tan, r_asin, r_acos, r_atan, rad_to_deg, deg_to_rad
function r_sin(x)
    return sin(x)
end

function r_cos(x)
    return cos(x)
end

function r_tan(x)
    return tan(x)
end

function r_asin(x)
    return asin(x)
end

function r_acos(x)
    return acos(x)
end

function r_atan(x)
    return atan(x)
end

function rad_to_deg(x)
    return x * 180 / π
end

function deg_to_rad(x)
    return x * π / 180
    end

#=
println(r_sin(π/2))
println(r_cos(0))
println(r_tan(π/4))
println()

println(r_asin(1))
println(r_acos(1))
println(r_atan(1))
println()

println(rad_to_deg(π))
println(deg_to_rad(180))
=#
end