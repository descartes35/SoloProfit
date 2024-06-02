<?php
require_once __DIR__ . '/../Repositorio/GestionRepositorio.inc';
require_once __DIR__ . '/../../app/utilidades/sanea.inc';
class GestionController
{
    // ====================CLIENTES====================//
    public function ClientesInicio()
    {
        require_once __DIR__ . '/../../app/plantillas/Gestion/Clientes/ClientesInicio.php';
    }
    public function ClientesVer()
    {
        $clientes = (new GestionRepositorio())->ObtenerClientesByIdUsuario($_SESSION['IDUsuario']);
        require_once __DIR__ . '/../../app/plantillas/Gestion/Clientes/ClientesVer.php';
    }
    public function ClientesAgregar()
    {
        if ($_SERVER['REQUEST_METHOD'] == 'POST') {
            if (empty($_POST['Nombre'])) {
                $_SESSION['errorNombreCli'] = "";
                header('Location: index.php?ctl=ClientesAñadir');
                exit();
            } else {
                $nombre = sanea($_POST['Nombre']);
                $email = sanea($_POST['Email']);
                $telefono = sanea($_POST['Telefono']);
                $direccion = sanea($_POST['Direccion']);
                $descripcion = sanea($_POST['Descripcion']);
                if ((new GestionRepositorio())->CrearCliente($_SESSION['IDUsuario'], $nombre, $email, $telefono, $direccion, $descripcion)) {
                    if (isset($_SESSION['errorNombreCli'])) {
                        unset($_SESSION['errorNombreCli']);
                    }
                    header('Location: index.php?ctl=ClientesGestion');
                    exit();
                }
            }
        }
        require_once __DIR__ . '/../../app/plantillas/Gestion/Clientes/ClientesAgregar.php';
    }

    public function ClientesEditar()
    {
        $id = $_GET['id'];
        $clienteRepo = new GestionRepositorio();
        $cliente = $clienteRepo->obtenerClienteById($id);

        if ($_SERVER['REQUEST_METHOD'] == 'POST') {
            $nombre = $_POST['nombre'];
            $email = $_POST['email'];
            $telefono = $_POST['telefono'];
            $direccion = $_POST['direccion'];
            $descripcion = $_POST['descripcion'];

            if ($clienteRepo->actualizarCliente($id, $nombre, $email, $telefono, $direccion, $descripcion)) {
                header('Location: index.php?ctl=ClientesInicio');
            } else {
                // Manejo de errores
            }
        }

        require_once __DIR__ . '/../../app/plantillas/Gestion/Clientes/ClientesActualizar.php';
    }
    public function ClientesBorrar()
    {
        if (isset($_GET['id'])) {
            $id = $_GET['id'];
            $clienteRepo = new GestionRepositorio();
            if ($clienteRepo->borrarCliente($id)) {
                header('Location: ' . $_SERVER['HTTP_REFERER']);
            } else {
                // Manejo de errores
            }
        }
    }
    // ====================CLIENTES====================//
    // ============================================================//
    // ====================PROVEEDORES====================//
    public function ProveedoresInicio()
    {
        require_once __DIR__ . '/../../app/plantillas/Gestion/Proveedores/ProveedoresInicio.php';
    }
    public function ProveedoresVer()
    {
        $proveedores = (new GestionRepositorio())->ObtenerProveedoresByIdUsuario($_SESSION['IDUsuario']);
        require_once __DIR__ . '/../../app/plantillas/Gestion/Proveedores/ProveedoresVer.php';
    }
    public function ProveedoresAgregar()
    {
        if ($_SERVER['REQUEST_METHOD'] == 'POST') {
            if (empty($_POST['Nombre'])) {
                $_SESSION['errorNombreProv'] = "";
                header('Location: index.php?ctl=ProveedoresAñadir');
                exit();
            } else {
                $nombre = sanea($_POST['Nombre']);
                $email = sanea($_POST['Email']);
                $telefono = sanea($_POST['Telefono']);
                $direccion = sanea($_POST['Direccion']);
                $descripcion = sanea($_POST['Descripcion']);
                if ((new GestionRepositorio())->CrearProveedor($_SESSION['IDUsuario'], $nombre, $email, $telefono, $direccion, $descripcion)) {
                    if (isset($_SESSION['errorNombreProv'])) {
                        unset($_SESSION['errorNombreProv']);
                    }
                    header('Location: index.php?ctl=ProveedoresGestion');
                    exit();
                }
            }
        }
        require_once __DIR__ . '/../../app/plantillas/Gestion/Proveedores/ProveedoresAgregar.php';
    }



    public function ProveedoresEditar()
    {
        $id = $_GET['id'];
        $proveedorRepo = new GestionRepositorio();
        $proveedor = $proveedorRepo->obtenerProveedorById($id);

        if ($_SERVER['REQUEST_METHOD'] == 'POST') {
            $nombre = $_POST['nombre'];
            $email = $_POST['email'];
            $telefono = $_POST['telefono'];
            $direccion = $_POST['direccion'];
            $descripcion = $_POST['descripcion'];

            if ($proveedorRepo->actualizarProveedor($id, $nombre, $email, $telefono, $direccion, $descripcion)) {
                header('Location: index.php?ctl=ProveedoresInicio');
            } else {
                // Manejo de errores
            }
        }

        require_once __DIR__ . '/../../app/plantillas/Gestion/Proveedores/ProveedoresActualizar.php';
    }





    public function ProveedoresBorrar()
    {
        if (isset($_GET['id'])) {
            $id = $_GET['id'];
            $proveedorRepo = new GestionRepositorio();
            if ($proveedorRepo->borrarProveedor($id)) {
                header('Location: ' . $_SERVER['HTTP_REFERER']);
            } else {
                // Manejo de errores
            }
        }
    }



    // ====================PROVEEDORES====================//
    // ============================================================//
    // ====================PROYECTOS====================//
    public function ProyectosInicio()
    {
        require_once __DIR__ . '/../../app/plantillas/Gestion/Proyectos/ProyectosInicio.php';
    }

    public function ProyectosVer()
    {
        $proyectos = (new GestionRepositorio())->ObtenerProyectosByIdUsuario($_SESSION['IDUsuario']);
        require_once __DIR__ . '/../../app/plantillas/Gestion/Proyectos/ProyectosVer.php';
    }

    public function ProyectosAgregar()
    {
        if ($_SERVER['REQUEST_METHOD'] == 'POST') {
            if (empty($_POST['Nombre']) || empty($_POST['Descripcion']) || empty($_POST['FechaInicio']) || empty($_POST['FechaFin'])) {
                $_SESSION['errorProyecto'] = "Todos los campos son obligatorios.";
                header('Location: index.php?ctl=ProyectosAñadir');
                exit();
            } else {
                $nombre = sanea($_POST['Nombre']);
                $descripcion = sanea($_POST['Descripcion']);
                $fechaInicio = sanea($_POST['FechaInicio']);
                $fechaFin = sanea($_POST['FechaFin']);

                if ((new GestionRepositorio())->crearProyecto($_SESSION['IDUsuario'], $nombre, $descripcion, $fechaInicio, $fechaFin)) {
                    if (isset($_SESSION['errorProyecto'])) {
                        unset($_SESSION['errorProyecto']);
                    }
                    header('Location: index.php?ctl=ProyectosGestion');
                    exit();
                } else {
                    $_SESSION['errorProyecto'] = "Error al crear el proyecto.";
                }
            }
        }
        require_once __DIR__ . '/../../app/plantillas/Gestion/Proyectos/ProyectosAgregar.php';
    }

    public function ProyectosEditar()
    {
        $id = $_GET['id'];
        $proyectoRepo = new GestionRepositorio();
        $proyecto = $proyectoRepo->obtenerProyectoById($id);

        if ($_SERVER['REQUEST_METHOD'] == 'POST') {
            $nombre = $_POST['nombre'];
            $descripcion = $_POST['descripcion'];
            $fechaInicio = $_POST['fechaInicio'];
            $fechaFin = $_POST['fechaFin'];

            if ($proyectoRepo->actualizarProyecto($id, $nombre, $descripcion, $fechaInicio, $fechaFin)) {
                header('Location: index.php?ctl=ProyectosInicio');
            } else {
                // Manejo de errores
            }
        }

        require_once __DIR__ . '/../../app/plantillas/Gestion/Proyectos/ProyectosActualizar.php';
    }
    public function ProyectosBorrar()
    {
        if (isset($_GET['id'])) {
            $id = $_GET['id'];
            $proyectoRepo = new GestionRepositorio();
            if ($proyectoRepo->borrarProyecto($id)) {
                header('Location: ' . $_SERVER['HTTP_REFERER']);
            } else {
                // Manejo de errores
            }
        }
    }
    // ====================PROYECTOS====================//
}
