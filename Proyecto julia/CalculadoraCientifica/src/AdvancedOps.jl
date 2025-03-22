module AdvancedOps
export power, squate_root, log_base, exp_n, root_n, log_nepher

function power(base, exponent)
    return base^exponent
end

function squate_root(num)
    return sqrt(num)
end

function log_base(num, Base=10)
    return log(num, Base)
end

function log_nepher(num)
    return log(num)
end

function exp_n(num)
    return exp(num)
end

function root_n(num, n)
    return num^(1 / n)
end

# testing the functions
#=
println(power(2, 3))  # Output: 8
println(squate_root(16))  # Output: 4.0
println(log_base(100))  # Output: 2.0
println(exp_n(1))  # Output: 2.718281828459045
println(root_n(8, 3))  # Output: 2.0
=#
end