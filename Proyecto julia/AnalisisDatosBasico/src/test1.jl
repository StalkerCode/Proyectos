using CSV
#using DataFrames

# Cargar los datos de las flores desde el archivo CSV
function cargar_hoja()
    path = "src/data/iris_data.csv"
    contenido = ""
    datos = []
    # Abre el archivo
    open(path, "r") do archivo
        # Lee el archivo
        contenido = read(archivo, String)
        # crea una vertor de cada linea del archivo
        lista = split(contenido, "\r\n")
        for fila in lista
            # convierte la vila en un vecto 
            subfila=split(fila,",")
            # convierte los datos en float
            nueva_fila = Any[parse(Float64, dato) for dato in subfila[1:end-1]]
            # agrega el tipo de flor al final de la fila
            push!(nueva_fila, subfila[end])
            push!(datos, nueva_fila)
        end
    end
    return datos
end
cargar_hoja()
