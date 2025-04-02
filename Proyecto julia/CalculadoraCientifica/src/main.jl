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
    print("Seleccione una opción")
end

function menuBasico()
    println("\nMenú de Operaciones Básicas")
    println("1. Suma")
    println("2. Resta")
    println("3. Multiplicación")
    println("4. División")
    println("5. Modulo")
    println("6. Volver")
    print("Seleccione una opción")
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
    print("Seleccione una opción")
end

function menuUtiles()
    println("\nMenú de Operaciones Utiles")
    println("1. Factorial")
    println("2. Maximo Comun Divisor")
    println("3. Minimo Comun Multiplo")
    println("4. Volver")
    print("Seleccione una opción")
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
    print("Seleccione una opción")
end

function ingresarEntero()
    while true
        print(": ")
        try
            return parse(Int, readline())
        catch
            println("ingrese un entero valido")
        end
    end
end

function ingresarNumero()
    while true
        print(": ")
        try
            return parse(Float32, readline())
        catch
            println("ingrese un entero valido")
        end
    end
end
function proseso(operacion)
    println("Ingrese el primer numero")
    num1 = ingresarNumero()
    println("Ingrese el segundo numero")
    num2 = ingresarNumero()
    return operacion(num1, num2)
end

function basico()
    while true
        menuBasico()
        op = ingresarEntero()
        resultado = 0
        if op == 1
            resultado = proseso(add)
        elseif op == 2
            resultado = proseso(subtract)
        elseif op == 3
            resultado = proseso(multiply)
        elseif op == 4
            resultado = proseso(divide)
            resultado = trunc(resultado, digits=2)
        elseif op == 5
            resultado = proseso(modulus)
            resultado = trunc(resultado, digits=2)
        elseif op == 6
            return
        else
            println("opcion equivocada")
            continue
        end
        println("El resultado es: ", resultado)
    end
end

function avanzadas()
    while true
        menuAvanzado()
        op = ingresarEntero()
        resultado = 0
        num1, num2 = (0, 0)
        if op == 1
            println("Ingrese la base")
            num1 = ingresarNumero()
            println("Ingrese el exponente")
            num2 = ingresarNumero()
            resultado = power(num1, num2)
            resultado = trunc(resultado, digits=2)
        elseif op == 2
            println("Ingrese numero")
            num1 = ingresarNumero()
            resultado = squate_root(num1)
            resultado = trunc(resultado, digits=2)
        elseif op == 3
            println("Ingrese numero")
            num1 = ingresarNumero()
            println("Ingrese la raiz")
            num2 = ingresarNumero()
            resultado = root_n(num1, num2)
            resultado = trunc(resultado, digits=2)
        elseif op == 4
            println("Ingrese el numero")
            num1 = ingresarNumero()
            resultado = log_nepher(num1)
            resultado = trunc(resultado, digits=2)
        elseif op == 5
            println("Ingrese el numero")
            num1 = ingresarNumero()
            println("Ingrese el log")
            num2 = ingresarNumero()
            resultado = log_base(num1, num2)
            resultado = trunc(resultado, digits=2)
        elseif op == 6
            println("Ingrese el exponente")
            num1 = ingresarNumero()
            resultado = exp_n(num1)
            resultado = trunc(resultado, digits=2)
        elseif op == 7
            return
        else
            println("opcion equivocada")
            continue
        end

        println("El resultado es: ", resultado)
    end
end

basico()
avanzadas()