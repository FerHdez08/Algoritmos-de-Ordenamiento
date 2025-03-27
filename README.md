# Análisis de Algoritmos de Ordenación
Análisis comparativo de tiempos de ejecución de los principales métodos de ordenación de datos comparados con la cantidad de datos a ordenar.

Los métodos de ordenación utilizados son:

  - Inserción
  - Burbuja Optimizado
  - Selección
  - Mezcla Sort
  - Quick Sort
  - Montículos
  - Shell

El programa consiste en ordenar un cojunto de datos con los métodos mencionados previamente y generar elementos graficos que auxilien a la comprensión acerca de las secuencias de pasos que tiene que llevar cada uno de estos, por lo que da resultados variando la cantidad de datos a ordenar y a su vez el método escogido , lo que produce una diversificación en los promedios de los tiempos.

El código inicializa con un procedimiento que se repite mil veces, donde en cada ocasión se generan 100 conjuntos de diferentes tamaños.

Los tamaños son:

   *10, 20, 30, 40, ..., 1000*                                       

Donde a cada conjunto del 10 al 1000 se le aplica un método de ordenación y se registra el vector de tiempos y eso se hace con los 7 métodos de ordenación, es decir, que después de completar el primer vector de tiempos para todos los métodos, procedemos a generar 100 nuevos conjuntos de números aleatorios en esta segunda repetición de las mil veces, para volver a aplicarle los 7 métodos, de manera sucesiva se realiza este procedimiento hasta completar 100 veces. 
Al final se calculan los promedios por método y por tamaño de los conjuntos de datos a ordenar, a su vez los datos son enviados a un archivo csv para cada uno de los métodos.

## Requisitos del sistema para ejecutar el código

## Compilación y ejecución del código

## Descripción de los algoritmos implementados

## Gráfica comparativa de los tiempos promedios de ejecución de los 7 algoritmos implementados

![Gráfica](https://github.com/FerHdez08/Algoritmos-de-Ordenamiento/raw/main/img/imgAlg.png)

