# **Get Next Line** 📄

## **Introducción**

Leer líneas desde un file descriptor puede parecer una tarea sencilla, pero implementar una solución eficiente y versátil en C es un desafío interesante. **Get Next Line** es un proyecto de la escuela 42 diseñado para enseñarte conceptos fundamentales, como el uso de variables estáticas y la gestión eficiente de memoria dinámica.

El objetivo es crear una función que lea y devuelva una línea completa desde un file descriptor. Este proyecto no solo amplía tu comprensión del lenguaje C, sino que también te permite agregar una herramienta práctica a tu colección de utilidades.

### **Objetivo**

Implementar la función `get_next_line`, que permite leer el contenido de un archivo o entrada estándar (stdin) línea por línea. La función debe devolver cada línea como un string, terminando en `\n` siempre que sea posible. Si se llega al final del archivo o ocurre un error, la función devolverá `NULL`.

### **Prototipo**
```c
char *get_next_line(int fd);
