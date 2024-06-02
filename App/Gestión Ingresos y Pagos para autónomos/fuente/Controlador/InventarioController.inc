<?php
require_once __DIR__ . '/../Repositorio/InventarioRepositorio.inc';

class InventarioController
{
    // ====================PRODUCTOS====================//
    public function ProductosInicio()
    {
        require_once __DIR__ . '/../../app/plantillas/Inventario/Productos/ProductosInicio.php';
    }

    public function ProductosVer()
    {
        $productos = (new InventarioRepositorio())->obtenerArticulosByIdUsuario($_SESSION['IDUsuario'], 'Producto');
        require_once __DIR__ . '/../../app/plantillas/Inventario/Productos/ProductosVer.php';
    }

    public function ProductosAgregar()
    {
        if ($_SERVER['REQUEST_METHOD'] == 'POST') {
            $nombre = sanea($_POST['Nombre']);
            $descripcion = sanea($_POST['Descripcion']);
            $precioCompra = sanea($_POST['PrecioCompra']);
            $precioVenta = sanea($_POST['PrecioVenta']);
            $stock = sanea($_POST['Stock']);
            $categoria = ucfirst(strtolower(sanea($_POST['Categoria'])));

            if ((new InventarioRepositorio())->agregarArticulo($_SESSION['IDUsuario'], $nombre, $descripcion, $precioCompra, $precioVenta, $stock, $categoria, 'Producto')) {
                header('Location: index.php?ctl=ProductoGestion');
                exit();
            } else {
                echo "Error al agregar el producto.";
            }
        }

        require_once __DIR__ . '/../../app/plantillas/Inventario/Productos/ProductosAgregar.php';
    }

    public function ProductosEditar()
    {
        $id = $_GET['id'];
        $productoRepo = new InventarioRepositorio();
        $producto = $productoRepo->obtenerArticuloPorId($id);

        if ($_SERVER['REQUEST_METHOD'] == 'POST') {
            $nombre = $_POST['nombre'];
            $categoria = $_POST['categoria'];
            $descripcion = $_POST['descripcion'];
            $precioCompra = $_POST['precioCompra'];
            $precioVenta = $_POST['precioVenta'];
            $stock = $_POST['stock'];

            if ($productoRepo->actualizarProducto($id, $nombre, $categoria, $descripcion, $precioCompra, $precioVenta, $stock)) {
                header('Location: index.php?ctl=ProductosInicio');
            } else {
                // Manejo de errores
            }
        }

        require_once __DIR__ . '/../../app/plantillas/Inventario/Productos/ProductosActualizar.php';
    }

    public function ProductosBorrar()
    {
        if (isset($_GET['id'])) {
            $id = $_GET['id'];
            $productoRepo = new InventarioRepositorio();
            if ($productoRepo->borrarProducto($id)) {
                header('Location: ' . $_SERVER['HTTP_REFERER']);
            } else {
                // Manejo de errores
            }
        }
    }
    // ====================PRODUCTOS====================//

    // ====================SERVICIOS====================//
    public function ServiciosInicio()
    {
        require_once __DIR__ . '/../../app/plantillas/Inventario/Servicios/ServiciosInicio.php';
    }

    public function ServiciosVer()
    {
        $servicios = (new InventarioRepositorio())->obtenerArticulosByIdUsuario($_SESSION['IDUsuario'], 'Servicio');
        require_once __DIR__ . '/../../app/plantillas/Inventario/Servicios/ServiciosVer.php';
    }

    public function ServiciosAgregar()
    {
        if ($_SERVER['REQUEST_METHOD'] == 'POST') {
            $nombre = sanea($_POST['Nombre']);
            $descripcion = sanea($_POST['Descripcion']);
            $categoria = ucfirst(strtolower(sanea($_POST['Categoria'])));

            if ((new InventarioRepositorio())->agregarArticulo($_SESSION['IDUsuario'], $nombre, $descripcion, 0, 0, 0, $categoria, 'Servicio')) {
                header('Location: index.php?ctl=ServicioGestion');
                exit();
            } else {
                echo "Error al agregar el servicio.";
            }
        }

        require_once __DIR__ . '/../../app/plantillas/Inventario/Servicios/ServiciosAgregar.php';
    }

    public function ServiciosEditar()
    {
        $id = $_GET['id'];
        $servicioRepo = new InventarioRepositorio();
        $servicio = $servicioRepo->obtenerArticuloPorId($id);

        if ($_SERVER['REQUEST_METHOD'] == 'POST') {
            $nombre = $_POST['nombre'];
            $categoria = $_POST['categoria'];
            $descripcion = $_POST['descripcion'];
            $fechaRegistro = $_POST['fechaRegistro'];
            $tipo = $_POST['tipo'];

            if ($servicioRepo->actualizarServicio($id, $nombre, $categoria, $descripcion, $fechaRegistro, $tipo)) {
                header('Location: index.php?ctl=ServiciosInicio');
            } else {
             echo("Error");
            }
        }

        require_once __DIR__ . '/../../app/plantillas/Inventario/Servicios/ServiciosActualizar.php';
    }

    public function ServiciosBorrar()
    {
        if (isset($_GET['id'])) {
            $id = $_GET['id'];
            $servicioRepo = new InventarioRepositorio();
            if ($servicioRepo->borrarServicio($id)) {
                header('Location: ' . $_SERVER['HTTP_REFERER']);
            } else {
                // Manejo de errores
            }
        }
    }
    // ====================SERVICIOS====================//
}
