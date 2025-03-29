include("BasicOps.jl")
include("AdvancedOps.jl")
include("TrigOps.jl")
include("Utils.jl")

using .BasicOps
using .AdvancedOps
using .TrigOps
using .Utils

function menuPrincipal()
    println("\nMenú Principal")
    println("1. Operaciones Básica")
    println("2. Operaciones Avanzadas")
    println("3. Operaciones Trigonometrica")
    println("4. Operaciones Utiles")
    println("5. Salir")
    print("Seleccione una opción: ")
end

function menuBasico()
    println("\nMenú de Operaciones Básicas")
    println("1. Suma")
    println("2. Resta")
    println("3. Multiplicación")
    println("4. División")
    println("5. Modulo")
    println("6. Volver")
    print("Seleccione una opción: ")
end

function menuAvanzado()
    println("\nMenú de Operaciones Avanzadas")
    println("1. Potencia")
    println("2. Raíz Cuadrada")
    println("3. Raíz a la N")
    println("4. Logaritmo Neperiano")
    println("5. Logaritmo Base N")
    println("6. Elurer a la N")
    println("7. Volver")
    print("Seleccione una opción: ")
end

function menuUtiles()
    println("\nMenú de Operaciones Utiles")
    println("1. Factorial")
    println("2. Maximo Comun Divisor")
    println("3. Minimo Comun Multiplo")
    println("4. Volver")
    print("Seleccione una opción: ")
end

function menuTrigonometrico()
    println("\nMenú de Operaciones Trigonometricas")
    println("1. Seno")
    println("2. Coseno")
    println("3. Tangente")
    println("4. Arco Seno")
    println("5. Arco Coseno")
    println("6. Arco Tangente")
    println("6. Radianes a Grados")
    println("7. Grados a Radianes")
    println("8. Volver")
    print("Seleccione una opción: ")
end

println(exp_n(1))  # Output: 2.718281828459045