#include <stdio.h>
#include <stdlib.h>


struct Producto
{
   int ID;
   int Cantidad;
   float Precio;
   char Nombre[30];
};

#define MAX_PRODUCTO 100
Producto inventario[MAX_PRODUCTO];
int num_producto = 0;


void Agregar_Producto();
void Mostrar_todos_los_productos();
void Actualizar_Productos();
void Eliminar_Productos();
void Salir_del_Programa();


int main() 
{
   int opcion;

   do
   {
      
      printf("\n\n=== Menu Principal ===\n\n");
      printf("1- Ver Productos\n");
      printf("2- Ingresar Producto\n");
      printf("3- Modificar producto por ID\n");
      printf("4- Eliminar Producto\n");
      printf("5- Salir\n\n");

      printf("Ingrese su eleccion: ");
      scanf("%d", &opcion);

      switch(opcion)
      {
         case 1:
         Mostrar_todos_los_productos();
         break;
         case 2:
         Agregar_Producto();
         break;
         case 3:
         Actualizar_Productos();
         break;
         case 4:
         Eliminar_Productos();
         break;
         case 5:
         Salir_del_Programa();
         break;
         default:
         printf("Opcion invalida\n");
         break;
      }
   }while(opcion != 5);
}

void Agregar_Producto()
{
   if(num_producto < MAX_PRODUCTO) 
   {
      Producto agregar_producto;

      
      printf("\nIngrese el ID del producto: ");
      scanf("%d", &agregar_producto.ID);
      getchar(); 
      printf("Ingrese el nombre del producto: ");
      fgets(agregar_producto.Nombre, 30, stdin);
      printf("Ingrese la cantidad del producto: ");
      scanf("%d", &agregar_producto.Cantidad);
      printf("Ingrese el precio del producto: ");
      scanf("%f", &agregar_producto.Precio);

      inventario[num_producto] = agregar_producto; 
      num_producto++; 

      
      printf("\n\nEl producto se agrego correctamente.");
   }
   else
   {
    
      printf("No hay espacio en el inventario");
   }
}

void Mostrar_todos_los_productos()
{
   if(num_producto > 0)
   {
      
      printf("\nLista de productos\n");

      for(int i = 0; i < num_producto; i++)
      {
         printf("\nProducto %d: \n", i+1);
         printf("ID: %d\n", inventario[i].ID);
         printf("Nombre: %s", inventario[i].Nombre);
         printf("Cantidad: %d\n", inventario[i].Cantidad);
         printf("Precio: %.2f\n", inventario[i].Precio);
      }
   }
   else
   {
    
      printf("\nNo hay ningun producto en el inventario.");
   }
}
void Actualizar_Productos()
{
   int ID;
   int encontrar = -1; 

   
   printf("\nIngrese el ID del producto: ");
   scanf("%d", &ID);

   for(int i = 0; i < num_producto; i++)
   {
      if(inventario[i].ID == ID)
      {
         encontrar = i;
         break;
      }
   }

   if(encontrar != -1)
   {
     
      Producto Actualizar_Productos;
      getchar();
      printf("\nIngrese el nuevo nombre del producto: ");
      fgets(Actualizar_Productos.Nombre, 30, stdin);
      printf("Ingrese la nueva cantidad del producto: ");
      scanf("%d", &Actualizar_Productos.Cantidad);
      printf("Ingrese el nuevo precio del producto: ");
      scanf("%f", &Actualizar_Productos.Precio);

      inventario[encontrar] = Actualizar_Productos;

      
      printf("\nProdcuto actualizado correctamente.");
   }
   else
   {
      
      printf("\nNo existe un producto con ese ID.");
   }
}
void Eliminar_Productos()
{
   int ID;
   int encontrar = -1;

   
   printf("Ingrese el ID del producto que desea eliminar: ");
   scanf("%d", &ID);

   for(int i = 0; i < num_producto; i++)
   {
      if(inventario[i].ID == ID)
      {
         encontrar = 1;
         break;
      }
   }

   if(encontrar != -1)
   {
      for(int i = encontrar; i < num_producto; i++)
      {
         inventario[i] = inventario[i + 1];
      }

      num_producto--;
      
      printf("\nProducto eliminado correctamente.");
   }
   else
   {
     
      printf("\nNo existe un producto con ese ID.");
   }
}
void Salir_del_Programa()
{
   
   printf("Gracias por usar el sistema de inventario.");
   exit(0);
}

