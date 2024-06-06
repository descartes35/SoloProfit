<?php
$mapeoRutas =
  [
    'inicio' => ['controller' => 'defaultController', 'action' => 'inicio'],
    // ====================================SESION====================================//
    // ========================================start====================//
    'SesionInicio' => ['controller' => 'SessionController', 'action' => 'iniciarSesion'],
    'SesionRegsitro' => ['controller' => 'SessionController', 'action' => 'registrarUsuario'],
    'registrarUsuario' => ['controller' => 'SessionController', 'action' => 'registrarUsuario'],
    'cerrarSesion' => ['controller' => 'SessionController', 'action' => 'cerrarSesion'],
    // ========================================end====================//
    // ====================================SESION====================================//
    //****************************************************************************************************//
    // ====================================INVENTARIO====================================//
    // ========================================start====================//
    // ===================Productos===================//
    'ProductosInicio' => ['controller' => 'InventarioController', 'action' => 'ProductosInicio'],
    'ProductoAñadir' => ['controller' => 'InventarioController', 'action' => 'ProductosAgregar'],
    'ProductoGestion' => ['controller' => 'InventarioController', 'action' => 'ProductosVer'],
    'ProductosEditar' => ['controller' => 'InventarioController', 'action' => 'ProductosEditar'],
    'ProductosBorrar' => ['controller' => 'InventarioController', 'action' => 'ProductosBorrar'],
    // ===================Servicios===================//
    'ServiciosInicio' => ['controller' => 'InventarioController', 'action' => 'ServiciosInicio'],
    'ServicioAñadir' => ['controller' => 'InventarioController', 'action' => 'ServiciosAgregar'],
    'ServicioGestion' => ['controller' => 'InventarioController', 'action' => 'ServiciosVer'],
    'ServiciosEditar' => ['controller' => 'InventarioController', 'action' => 'ServiciosEditar'],
    'ServiciosBorrar' => ['controller' => 'InventarioController', 'action' => 'ServiciosBorrar'],
    // ========================================end====================//
    // ====================================INVENTARIO====================================//
    //****************************************************************************************************//
    // ====================================GESTIÓN====================================//
    // ========================================start====================//
    // ===================Clientes===================//
    'ClientesInicio' => ['controller' => 'GestionController', 'action' => 'ClientesInicio'],
    'ClientesAñadir' => ['controller' => 'GestionController', 'action' => 'ClientesAgregar'],
    'ClientesGestion' => ['controller' => 'GestionController', 'action' => 'ClientesVer'],
    'ClientesEditar' => ['controller' => 'GestionController', 'action' => 'ClientesEditar'],
    'ClientesBorrar' => ['controller' => 'GestionController', 'action' => 'ClientesBorrar'],
    // ===================Proveedores===================//
    'ProveedoresInicio' => ['controller' => 'GestionController', 'action' => 'ProveedoresInicio'],
    'ProveedoresAñadir' => ['controller' => 'GestionController', 'action' => 'ProveedoresAgregar'],
    'ProveedoresGestion' => ['controller' => 'GestionController', 'action' => 'ProveedoresVer'],
    'ProveedoresEditar' => ['controller' => 'GestionController', 'action' => 'ProveedoresEditar'],
    'ProveedoresBorrar' => ['controller' => 'GestionController', 'action' => 'ProveedoresBorrar'],
    // ===================Proyectos===================//
    'ProyectosInicio' => ['controller' => 'GestionController', 'action' => 'ProyectosInicio'],
    'ProyectosAñadir' => ['controller' => 'GestionController', 'action' => 'ProyectosAgregar'],
    'ProyectosGestion' => ['controller' => 'GestionController', 'action' => 'ProyectosVer'],
    'ProyectosEditar' => ['controller' => 'GestionController', 'action' => 'ProyectosEditar'],
    'ProyectosBorrar' => ['controller' => 'GestionController', 'action' => 'ProyectosBorrar'],
    // ========================================end====================//
    // ====================================GESTIÓN====================================//
    //****************************************************************************************************//
    // ====================================CITAS====================================//
    // ========================================start====================//
    'NuevaCita' => ['controller' => 'CitasController', 'action' => 'NuevaCita'],
    'VerCitas' => ['controller' => 'CitasController', 'action' => 'VerCitas'],
    'CitasBorrar' => ['controller' => 'CitasController', 'action' => 'CitasBorrar'],
    'CitasEditar' => ['controller' => 'CitasController', 'action' => 'CitasEditar'],
    // ========================================end====================//
    // ====================================CITAS====================================//
    //****************************************************************************************************//
    // ====================================RESUMEN====================================//
    // ========================================start====================//
    'resumen' => ['controller' => 'ResumenController', 'action' => 'MostrarResumen'],
    // ========================================end====================//
    // ====================================RESUMEN====================================//
    //****************************************************************************************************//
    // ====================================REGISTRO_ANALISIS====================================//
    // ========================================start====================//
    'registroIngreso' => ['controller' => 'Registro_Analisis_Controller', 'action' => 'registroIngreso'],
    'registroGasto' => ['controller' => 'Registro_Analisis_Controller', 'action' => 'registroGasto'],
    'analisisFinanciero' => ['controller' => 'Registro_Analisis_Controller', 'action' => 'analisisFinanciero'],
    'reportes_financieros' => ['controller' => 'Registro_Analisis_Controller', 'action' => 'reporteFinancieroView'],
    'generarReporte' => ['controller' => 'Registro_Analisis_Controller', 'action' => 'generarReporte'],

    // ========================================end====================//
    // ====================================REGISTRO_ANALISIS====================================//
    //****************************************************************************************************//
    // ====================================PERSONALIZACIÓN USUARIO====================================//
    // ========================================start====================//
    'personalizacion' => ['controller' => 'PersonalizacionController', 'action' => 'editarUsuario'],
    // ========================================end====================//
    // ====================================PERSONALIZACIÓN USUARIO====================================//

  ];
