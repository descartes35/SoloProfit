<?php

use Fpdf\Fpdf;

require_once __DIR__ . '/../Repositorio/Registro_Analisis_Repositorio.inc';
require_once __DIR__ . '/../Repositorio/CitasRepositorio.inc';
require_once __DIR__ . '/../Repositorio/GestionRepositorio.inc';
require_once __DIR__ . '/../Repositorio/InventarioRepositorio.inc';
require_once __DIR__ . '/../Repositorio/UsuarioRepositorio.inc';
require_once __DIR__ . '/../../../../vendor/autoload.php';


class Registro_Analisis_Controller
{
    public function registroIngreso()
    {
        if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['categoriaIngreso'], $_POST['monto_ingreso'], $_POST['descripcion_ingreso'], $_POST['fecha_ingreso'])) {
            // Obtener los datos del formulario
            $nombreCategoria = $_POST['categoriaIngreso'];
            $monto = $_POST['monto_ingreso'];
            $descripcion = $_POST['descripcion_ingreso'];
            $fecha = $_POST['fecha_ingreso'];

            // Crear una instancia del modelo Registro_Analisis
            $registroAnalisis = new Registro_Analisis();

            // Llamar a la función registrarIngreso del modelo
            $registroExitoso = $registroAnalisis->registrarIngreso($nombreCategoria, $monto, $descripcion, $_SESSION['IDUsuario'], $fecha);

            // Redireccionar a una página de éxito o mostrar un mensaje
            if ($registroExitoso) {
                // Redirigir a una página de éxito
                header('Location: index.php?ctl=analisisFinanciero');
                exit();
            } else {
                // Mostrar un mensaje de error
                echo "Error al registrar el ingreso.";
            }
        } else {
            // Mostrar el formulario para registrar ingreso
            require_once __DIR__ . '/../../app/plantillas/Registro_Analisis/Ingresos/Ingresos.php';
        }
    }

    public function registroGasto()
    {
        if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['categoriaGasto'], $_POST['monto_gasto'], $_POST['descripcion_gasto'], $_POST['fecha_gasto'])) {
            // Obtener los datos del formulario
            $nombreCategoria = $_POST['categoriaGasto'];
            $monto = $_POST['monto_gasto'];
            $descripcion = $_POST['descripcion_gasto'];
            $idUsuario = $_SESSION['IDUsuario'];
            $fecha = $_POST['fecha_gasto'];

            // Crear una instancia del modelo Registro_Analisis
            $registroAnalisis = new Registro_Analisis();

            // Llamar a la función registrarGasto del modelo
            $registroExitoso = $registroAnalisis->registrarGasto($nombreCategoria, $monto, $descripcion, $idUsuario, $fecha);

            // Redireccionar a una página de éxito o mostrar un mensaje
            if ($registroExitoso) {
                // Redirigir a una página de éxito
                header('Location: index.php?ctl=analisisFinanciero');
                exit();
            } else {
                // Mostrar un mensaje de error
                echo "Error al registrar el gasto.";
            }
        } else {
            // Mostrar el formulario para registrar gasto
            require_once __DIR__ . '/../../app/plantillas/Registro_Analisis/Gastos/Gastos.php';
        }
    }

    public function analisisFinanciero()
    {
        require_once __DIR__ . '/../Repositorio/Registro_Analisis_Repositorio.inc';
        $registroAnalisis = new Registro_Analisis();
        $ingresosPorUsuario = $registroAnalisis->obtenerIngresosPorUsuario($_SESSION['IDUsuario']);
        $gastosPorUsuario = $registroAnalisis->obtenerGastosPorUsuario($_SESSION['IDUsuario']);
        $balanceFinanciero = $registroAnalisis->obtenerBalanceFinancieroPorUsuario($_SESSION['IDUsuario']);
        $ingresosPorCategoria = $registroAnalisis->obtenerIngresosPorCategoria($_SESSION['IDUsuario']);
        $gastosPorCategoria = $registroAnalisis->obtenerGastosPorCategoria($_SESSION['IDUsuario']);
        $ingresosPorMes = $registroAnalisis->obtenerIngresosPorMes($_SESSION['IDUsuario']);
        $gastosPorMes = $registroAnalisis->obtenerGastosPorMes($_SESSION['IDUsuario']);
        require_once __DIR__ . '/../../app/plantillas/Registro_Analisis/AnalisisFinanciero/analisisFinanciero.php';
    }

    public function reporteFinancieroView()
    {
        require_once __DIR__ . '/../../app/plantillas/Registro_Analisis/ReporteFinanciero/reporteFinanciero.php';
    }

    public function generarReporte()
    {
        // Iniciar el almacenamiento en búfer de salida
        ob_start();

        $registroAnalisis = new Registro_Analisis();

        // Obtener datos del usuario
        $usuarioRepo = new UsuarioRepositorio();
        $usuario = $usuarioRepo->getDatosUsuarioByCorreo($_SESSION['Email']);

        // Obtener datos financieros
        $ingresos = $registroAnalisis->obtenerIngresosPorUsuario($_SESSION['IDUsuario']);
        $gastos = $registroAnalisis->obtenerGastosPorUsuario($_SESSION['IDUsuario']);
        $balance = $registroAnalisis->obtenerBalanceFinancieroPorUsuario($_SESSION['IDUsuario']);
        $ingresosPorCategoria = $registroAnalisis->obtenerIngresosPorCategoria($_SESSION['IDUsuario']);
        $gastosPorCategoria = $registroAnalisis->obtenerGastosPorCategoria($_SESSION['IDUsuario']);

        // Obtener datos adicionales
        $proveedores = (new GestionRepositorio())->ObtenerProveedoresByIdUsuario($_SESSION['IDUsuario']);
        $inventario = (new InventarioRepositorio())->obtenerArticulosByIdUsuarioSinTipo($_SESSION['IDUsuario']);
        $citas = (new CitasRepositorio())->obtenerCitasByIdUsuario($_SESSION['IDUsuario']);
        $clientes = (new GestionRepositorio())->ObtenerClientesByIdUsuario($_SESSION['IDUsuario']);
        $proyectos = (new GestionRepositorio())->ObtenerProyectosByIdUsuario($_SESSION['IDUsuario']);

        $ingresosPorMes = $registroAnalisis->obtenerIngresosPorMes($_SESSION['IDUsuario']);
        $gastosPorMes = $registroAnalisis->obtenerGastosPorMes($_SESSION['IDUsuario']);

        // Crear el PDF
        $pdf = new Fpdf();
        $pdf->AddPage();
        $pdf->SetAutoPageBreak(true, 10);

        // Encabezado
        $pdf->SetFont('Arial', 'B', 16);
        $pdf->Cell(0, 10, 'Reporte Financiero', 0, 1, 'C');
        $pdf->SetFont('Arial', 'B', 12);
        $pdf->Cell(0, 10, 'Usuario: ' . $usuario['Nombre'] . ' ' . $usuario['Apellidos'], 0, 1, 'L');
        $pdf->Cell(0, 10, 'Email: ' . $usuario['Email'], 0, 1, 'L');
        $pdf->Ln(10);

        // Ingresos
        $pdf->SetFont('Arial', 'B', 14);
        $pdf->Cell(0, 10, 'Ingresos', 0, 1, 'L');
        $pdf->SetFont('Arial', 'B', 12);
        $pdf->Cell(40, 10, 'Fecha', 1);
        $pdf->Cell(40, 10, 'Monto', 1);
        $pdf->Cell(110, 10, 'Descripcion', 1);
        $pdf->Ln();
        $pdf->SetFont('Arial', '', 12);
        foreach ($ingresos as $ingreso) {
            $fechaFormateada = date('Y-m-d', strtotime($ingreso['Fecha']));
            $pdf->Cell(40, 10, $fechaFormateada, 1);
            $pdf->Cell(40, 10, number_format($ingreso['TotalIngresos'], 2), 1);
            $pdf->Cell(110, 10, $ingreso['Descripcion'], 1);
            $pdf->Ln();
        }
        $pdf->Ln(10);

        // Gastos
        $pdf->SetFont('Arial', 'B', 14);
        $pdf->Cell(0, 10, 'Gastos', 0, 1, 'L');
        $pdf->SetFont('Arial', 'B', 12);
        $pdf->Cell(40, 10, 'Fecha', 1);
        $pdf->Cell(40, 10, 'Monto', 1);
        $pdf->Cell(110, 10, 'Descripcion', 1);
        $pdf->Ln();
        $pdf->SetFont('Arial', '', 12);
        foreach ($gastos as $gasto) {
            $fechaFormateada = date('Y-m-d', strtotime($gasto['Fecha']));
            $pdf->Cell(40, 10, $fechaFormateada, 1);
            $pdf->Cell(40, 10, number_format($gasto['TotalGastos'], 2), 1);
            $pdf->Cell(110, 10, $gasto['Descripcion'], 1);
            $pdf->Ln();
        }
        $pdf->Ln(10);

        // Balance
        $pdf->SetFont('Arial', 'B', 14);
        $pdf->Cell(0, 10, 'Balance Financiero', 0, 1, 'L');
        $pdf->SetFont('Arial', '', 12);
        $pdf->Cell(0, 10, 'Total Ingresos: ' . number_format($balance[0]['TotalIngresos'], 2), 0, 1, 'L');
        $pdf->Cell(0, 10, 'Total Gastos: ' . number_format($balance[0]['TotalGastos'], 2), 0, 1, 'L');
        $pdf->Cell(0, 10, 'Balance: ' . number_format($balance[0]['Balance'], 2), 0, 1, 'L');
        $pdf->Ln(10);

        // Ingresos por Categoria
        $pdf->SetFont('Arial', 'B', 14);
        $pdf->Cell(0, 10, 'Ingresos por Categoria', 0, 1, 'L');
        $pdf->SetFont('Arial', 'B', 12);
        $pdf->Cell(80, 10, 'Categoria', 1);
        $pdf->Cell(40, 10, 'Monto', 1);
        $pdf->Ln();
        $pdf->SetFont('Arial', '', 12);
        foreach ($ingresosPorCategoria as $categoria) {
            $pdf->Cell(80, 10, $categoria['Categoria'], 1);
            $pdf->Cell(40, 10, number_format($categoria['TotalIngresos'], 2), 1);
            $pdf->Ln();
        }
        $pdf->Ln(10);

        // Gastos por Categoria
        $pdf->SetFont('Arial', 'B', 14);
        $pdf->Cell(0, 10, 'Gastos por Categoria', 0, 1, 'L');
        $pdf->SetFont('Arial', 'B', 12);

        $pdf->Cell(80, 10, 'Categoria', 1);
        $pdf->Cell(40, 10, 'Monto', 1);
        $pdf->Ln();
        $pdf->SetFont('Arial', '', 12);
        foreach ($gastosPorCategoria as $categoria) {
            $pdf->Cell(80, 10, $categoria['Categoria'], 1);
            $pdf->Cell(40, 10, number_format($categoria['TotalGastos'], 2), 1);
            $pdf->Ln();
        }
        $pdf->Ln(10);

        // Proveedores
        $pdf->SetFont('Arial', 'B', 14);
        $pdf->Cell(0, 10, 'Proveedores', 0, 1, 'L');
        $pdf->SetFont('Arial', 'B', 12);
        $pdf->Cell(40, 10, 'Nombre', 1);
        $pdf->Cell(40, 10, 'Telefono', 1);
        $pdf->Cell(60, 10, 'Direccion', 1);
        $pdf->Cell(50, 10, 'Email', 1);
        $pdf->Ln();
        $pdf->SetFont('Arial', '', 12);
        foreach ($proveedores as $proveedor) {
            $pdf->Cell(40, 10, $proveedor['Nombre'], 1);
            $pdf->Cell(40, 10, $proveedor['Telefono'], 1);
            $pdf->Cell(60, 10, $proveedor['Direccion'], 1);
            $pdf->Cell(50, 10, $proveedor['Email'], 1);
            $pdf->Ln();
        }
        $pdf->Ln(10);

        // Inventario
        $pdf->SetFont('Arial', 'B', 14);
        $pdf->Cell(0, 10, 'Inventario', 0, 1, 'L');
        $pdf->SetFont('Arial', 'B', 12);
        $pdf->Cell(40, 10, 'Articulo', 1);
        $pdf->Cell(40, 10, 'Cantidad', 1);
        $pdf->Cell(40, 10, 'Precio Unitario', 1);
        $pdf->Cell(60, 10, 'Descripcion', 1);
        $pdf->Ln();
        $pdf->SetFont('Arial', '', 12);
        foreach ($inventario as $articulo) {
            $pdf->Cell(40, 10, $articulo['Nombre'], 1);
            $pdf->Cell(40, 10, $articulo['Stock'], 1);
            $pdf->Cell(40, 10, number_format($articulo['PrecioCompra'], 2), 1);
            $pdf->Cell(60, 10, $articulo['Descripcion'], 1);
            $pdf->Ln();
        }
        $pdf->Ln(10);

        // Citas
        $pdf->SetFont('Arial', 'B', 14);
        $pdf->Cell(0, 10, 'Citas', 0, 1, 'L');
        $pdf->SetFont('Arial', 'B', 12);
        $pdf->Cell(40, 10, 'Fecha y Hora', 1);
        $pdf->Cell(70, 10, 'Descripcion', 1);
        $pdf->Ln();
        $pdf->SetFont('Arial', '', 12);
        foreach ($citas as $cita) {
            $fechaHoraFormateada = date('Y-m-d H:i:s', strtotime($cita['FechaHora']));
            $pdf->Cell(40, 10, $fechaHoraFormateada, 1);
            $pdf->Cell(70, 10, $cita['Descripcion'], 1);
            $pdf->Ln();
        }
        $pdf->Ln(10);


        // Clientes
        $pdf->SetFont('Arial', 'B', 14);
        $pdf->Cell(0, 10, 'Clientes', 0, 1, 'L');
        $pdf->SetFont('Arial', 'B', 12);
        $pdf->Cell(40, 10, 'Nombre', 1);
        $pdf->Cell(40, 10, 'Telefono', 1);
        $pdf->Cell(60, 10, 'Direccion', 1);
        $pdf->Cell(50, 10, 'Email', 1);
        $pdf->Ln();
        $pdf->SetFont('Arial', '', 12);
        foreach ($clientes as $cliente) {
            $pdf->Cell(40, 10, $cliente['Nombre'], 1);
            $pdf->Cell(40, 10, $cliente['Telefono'], 1);
            $pdf->Cell(60, 10, $cliente['Direccion'], 1);
            $pdf->Cell(50, 10, $cliente['Email'], 1);
            $pdf->Ln();
        }
        $pdf->Ln(10);

        // Proyectos
        $pdf->SetFont('Arial', 'B', 14);
        $pdf->Cell(0, 10, 'Proyectos', 0, 1, 'L');
        $pdf->SetFont('Arial', 'B', 12);
        $pdf->Cell(40, 10, 'Nombre', 1);
        $pdf->Cell(60, 10, 'Fecha de Inicio', 1);
        $pdf->Cell(60, 10, 'Fecha de Fin', 1);
        $pdf->Ln();
        $pdf->SetFont('Arial', '', 12);
        foreach ($proyectos as $proyecto) {
            $fechaInicioFormateada = date('Y-m-d', strtotime($proyecto['FechaInicio']));
            $fechaFinFormateada = date('Y-m-d', strtotime($proyecto['FechaFin']));
            $pdf->Cell(40, 10, $proyecto['Nombre'], 1);
            $pdf->Cell(60, 10, $fechaInicioFormateada, 1);
            $pdf->Cell(60, 10, $fechaFinFormateada, 1);
            $pdf->Ln();
        }
        $pdf->Ln(10);

        // Salida del PDF
        $pdf->Output();
        ob_end_flush();
    }
}