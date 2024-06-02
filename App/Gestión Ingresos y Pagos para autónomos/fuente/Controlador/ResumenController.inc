<?php
class ResumenController
{
    public function MostrarResumen()
    {
        require_once __DIR__ . '/../Repositorio/CitasRepositorio.inc';
        require_once __DIR__ . '/../Repositorio/GestionRepositorio.inc';
        require_once __DIR__ . '/../Repositorio/InventarioRepositorio.inc';
        require_once __DIR__ . '/../Repositorio/Registro_Analisis_Repositorio.inc';
        require_once __DIR__ . '/../Repositorio/UsuarioRepositorio.inc';

        $CitasRepositorio = new CitasRepositorio();
        $GestionRepositorio = new GestionRepositorio();
        $InventarioRepositorio = new InventarioRepositorio();
        $Registro_Analisis_Repositorio = new Registro_Analisis();
        // $UsuarioRepositorio = new UsuarioRepositorio();

        // Obtener citas
        $citas = $CitasRepositorio->obtenerCitasByIdUsuario($_SESSION['IDUsuario']);

        // Obtener proveedores
        $proveedores = $GestionRepositorio->ObtenerProveedoresByIdUsuario($_SESSION['IDUsuario']);

        // Obtener información financiera
        $ingresos = $Registro_Analisis_Repositorio->obtenerIngresosPorUsuario($_SESSION['IDUsuario']);
        $gastos = $Registro_Analisis_Repositorio->obtenerGastosPorUsuario($_SESSION['IDUsuario']);
        $balances = $Registro_Analisis_Repositorio->obtenerBalanceFinancieroPorUsuario($_SESSION['IDUsuario']);

        // Obtener artículos del inventario
        $articulos = $InventarioRepositorio->obtenerArticulosByIdUsuarioSinTipo($_SESSION['IDUsuario']);
        require_once __DIR__ . '/../../app/plantillas/resumen.php';
    }
}
