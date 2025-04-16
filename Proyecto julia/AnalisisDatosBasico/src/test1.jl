# funcion para cargar los datos de la flores
using CSV
using DataFrames

function cargar_hoja()
    # Cargar los datos de las flores desde el archivo CSV
    path = "src/data/iris_data.csv"
    # Leer el contenido del archivo
    contenido = ""
    open(path, "r") do archivo
        contenido = read(archivo, String)
    end
    println(contenido)
end
#=
function cargar_datos()
    # Ruta del archivo CSV
    path = "src/data/iris_data.csv"
    # Leer el archivo CSV sin encabezado
    datos = CSV.read(path, DataFrame; header=false)
    # Definir los nombres de las columnas
    nombres_columnas = ["ancho_tepalo", "largo_tepalo", "ancho_cepalo", "largo_cepalo", "tipo_flor"]
    # Asignar los nombres de las columnas al DataFrame
    rename!(datos, nombres_columnas)
    return datos
end
println(cargar_datos())
=#