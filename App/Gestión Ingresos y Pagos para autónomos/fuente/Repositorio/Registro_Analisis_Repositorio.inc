<?php
require_once __DIR__ . '/../../core/conexionBd.inc';
class Registro_Analisis
{
    public function registrarIngreso($nombre, $monto, $descripcion, $idUsuario, $fecha)
    {
        try {
            // Convertir la primera letra del nombre a mayúsculas
            $nombre = ucfirst($nombre);

            // Primero, insertamos la categoría de ingreso
            $sql = "INSERT INTO dbo.CategoriasIngresos (Nombre, Descripcion) VALUES (:nombre, :descripcion)";
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindParam(":nombre", $nombre);
            $stn->bindParam(":descripcion", $descripcion);
            $stn->execute();

            // Obtenemos el ID de la categoría de ingreso recién insertada
            $idCategoria = $conexion->lastInsertId();

            // Ahora insertamos el ingreso utilizando el ID de la categoría de ingreso
            $sql2 = "INSERT INTO dbo.Ingresos (IDUsuario, IDCategoriaIngreso, Monto, Moneda, Fecha, Descripcion) 
                     VALUES (:IDUsuario, :IDCategoriaIngreso, :monto, '€', CONVERT(DATETIME, :fecha, 120), :descripcion)";
            $stn2 = $conexion->prepare($sql2);

            $stn2->bindParam(":IDUsuario", $idUsuario);
            $stn2->bindParam(":IDCategoriaIngreso", $idCategoria);
            $stn2->bindParam(":monto", $monto);
            $stn2->bindParam(":descripcion", $descripcion);
            $stn2->bindParam(":fecha", $fecha);
            $stn2->execute();

            return true;
        } catch (\Throwable $th) {
            // Manejo de errores
            return false;
        } finally {
            // Cierre de conexiones y liberación de recursos
            if (isset($conexion)) {
                unset($conexion);
            }
            if (isset($stn)) {
                unset($stn);
            }
            if (isset($stn2)) {
                unset($stn2);
            }
        }
    }

    public function registrarGasto($nombre, $monto, $descripcion, $idUsuario, $fecha)
    {
        try {
            // Convertir la primera letra del nombre a mayúsculas
            $nombre = ucfirst($nombre);

            // Primero, insertamos la categoría de gasto
            $sql = "INSERT INTO dbo.CategoriasGastos (Nombre, Descripcion) VALUES (:nombre, :descripcion)";
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindParam(":nombre", $nombre);
            $stn->bindParam(":descripcion", $descripcion);
            $stn->execute();

            // Obtenemos el ID de la categoría de gasto recién insertada
            $idCategoria = $conexion->lastInsertId();

            // Ahora insertamos el gasto utilizando el ID de la categoría de gasto
            $sql2 = "INSERT INTO dbo.Gastos (IDUsuario, IDCategoriaGasto, Monto, Fecha, Descripcion) 
                     VALUES (:IDUsuario, :IDCategoriaGasto, :monto,  CONVERT(DATETIME, :fecha, 120), :descripcion)";
            $stn2 = $conexion->prepare($sql2);

            $stn2->bindParam(":IDUsuario", $idUsuario);
            $stn2->bindParam(":IDCategoriaGasto", $idCategoria);
            $stn2->bindParam(":monto", $monto);
            $stn2->bindParam(":fecha", $fecha);
            $stn2->bindParam(":descripcion", $descripcion);
            $stn2->execute();

            return true;
        } catch (\Throwable $th) {
            // Manejo de errores
            return false;
        } finally {
            // Cierre de conexiones y liberación de recursos
            if (isset($conexion)) {
                unset($conexion);
            }
            if (isset($stn)) {
                unset($stn);
            }
            if (isset($stn2)) {
                unset($stn2);
            }
        }
    }

    public function obtenerIngresosPorUsuario($IDUsuario)
    {
        try {
            $sql = "SELECT 
            u.IDUsuario, 
            u.Nombre, 
            u.Apellidos, 
            i.Fecha, 
            i.Descripcion,
            SUM(i.Monto) AS TotalIngresos
        FROM 
            Usuarios u
        JOIN 
            Ingresos i ON u.IDUsuario = i.IDUsuario
        WHERE 
            u.IDUsuario = :IDUsuario
        GROUP BY 
            u.IDUsuario, u.Nombre, u.Apellidos, i.Fecha, i.Descripcion";
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindParam(':IDUsuario', $IDUsuario, PDO::PARAM_INT);
            $stn->execute();
            return $stn->fetchAll();
        } catch (\Throwable $th) {
            return false;
        } finally {
            if (isset($conexion)) {
                unset($conexion);
            }
            if (isset($stn)) {
                unset($stn);
            }
        }
    }

    public function obtenerGastosPorUsuario($IDUsuario)
    {
        try {
            $sql = "SELECT 
                        u.IDUsuario, 
                        u.Nombre, 
                        u.Apellidos, 
                        g.Fecha, 
                        g.Descripcion,
                        SUM(g.Monto) AS TotalGastos
                    FROM 
                        Usuarios u
                    JOIN 
                        Gastos g ON u.IDUsuario = g.IDUsuario
                    WHERE 
                        u.IDUsuario = :IDUsuario
                    GROUP BY 
                        u.IDUsuario, u.Nombre, u.Apellidos, g.Fecha, g.Descripcion";
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindParam(':IDUsuario', $IDUsuario, PDO::PARAM_INT);
            $stn->execute();
            return $stn->fetchAll();
        } catch (\Throwable $th) {
            return false;
        } finally {
            if (isset($conexion)) {
                unset($conexion);
            }
            if (isset($stn)) {
                unset($stn);
            }
        }
    }


    public function obtenerBalanceFinancieroPorUsuario($IDUsuario)
    {
        try {
            $sql = "SELECT 
                        u.IDUsuario, 
                        u.Nombre, 
                        u.Apellidos, 
                        COALESCE(SUM(i.Monto), 0) AS TotalIngresos, 
                        COALESCE(SUM(g.Monto), 0) AS TotalGastos, 
                        COALESCE(SUM(i.Monto), 0) - COALESCE(SUM(g.Monto), 0) AS Balance
                    FROM 
                        Usuarios u
                    LEFT JOIN 
                        Ingresos i ON u.IDUsuario = i.IDUsuario
                    LEFT JOIN 
                        Gastos g ON u.IDUsuario = g.IDUsuario
                    WHERE 
                        u.IDUsuario = :IDUsuario
                    GROUP BY 
                        u.IDUsuario, u.Nombre, u.Apellidos";
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindParam(':IDUsuario', $IDUsuario, PDO::PARAM_INT);
            $stn->execute();
            return $stn->fetchAll();
        } catch (\Throwable $th) {
            return false;
        } finally {
            if (isset($conexion)) {
                unset($conexion);
            }
            if (isset($stn)) {
                unset($stn);
            }
        }
    }

    public function obtenerIngresosPorCategoria($IDUsuario)
    {
        try {
            $sql = "SELECT 
                        ci.Nombre AS Categoria, 
                        SUM(i.Monto) AS TotalIngresos
                    FROM 
                        CategoriasIngresos ci
                    JOIN 
                        Ingresos i ON ci.IDCategoriaIngreso = i.IDCategoriaIngreso
                    JOIN 
                        Usuarios u ON i.IDUsuario = u.IDUsuario
                    WHERE 
                        u.IDUsuario = :IDUsuario
                    GROUP BY 
                        ci.Nombre";
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindParam(':IDUsuario', $IDUsuario, PDO::PARAM_INT);
            $stn->execute();
            return $stn->fetchAll();
        } catch (\Throwable $th) {
            return false;
        } finally {
            if (isset($conexion)) {
                unset($conexion);
            }
            if (isset($stn)) {
                unset($stn);
            }
        }
    }

    public function obtenerGastosPorCategoria($IDUsuario)
    {
        try {
            $sql = "SELECT 
                        cg.Nombre AS Categoria, 
                        SUM(g.Monto) AS TotalGastos
                    FROM 
                        CategoriasGastos cg
                    JOIN 
                        Gastos g ON cg.IDCategoriaGasto = g.IDCategoriaGasto
                    JOIN 
                        Usuarios u ON g.IDUsuario = u.IDUsuario
                    WHERE 
                        u.IDUsuario = :IDUsuario
                    GROUP BY 
                        cg.Nombre";
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindParam(':IDUsuario', $IDUsuario, PDO::PARAM_INT);
            $stn->execute();
            return $stn->fetchAll();
        } catch (\Throwable $th) {
            return false;
        } finally {
            if (isset($conexion)) {
                unset($conexion);
            }
            if (isset($stn)) {
                unset($stn);
            }
        }
    }

    public function obtenerIngresosPorMes($IDUsuario)
    {
        try {
            $sql = "SELECT 
                        YEAR(i.Fecha) AS Año, 
                        MONTH(i.Fecha) AS Mes, 
                        SUM(i.Monto) AS TotalIngresos
                    FROM 
                        Ingresos i
                    JOIN 
                        Usuarios u ON i.IDUsuario = u.IDUsuario
                    WHERE 
                        u.IDUsuario = :IDUsuario
                    GROUP BY 
                        YEAR(i.Fecha), 
                        MONTH(i.Fecha)
                    ORDER BY 
                        Año, Mes";
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindParam(':IDUsuario', $IDUsuario, PDO::PARAM_INT);
            $stn->execute();
            return $stn->fetchAll();
        } catch (\Throwable $th) {
            return false;
        } finally {
            if (isset($conexion)) {
                unset($conexion);
            }
            if (isset($stn)) {
                unset($stn);
            }
        }
    }

    public function obtenerGastosPorMes($IDUsuario)
    {
        try {
            $sql = "SELECT 
                        YEAR(g.Fecha) AS Año, 
                        MONTH(g.Fecha) AS Mes, 
                        SUM(g.Monto) AS TotalGastos
                    FROM 
                        Gastos g
                    JOIN 
                        Usuarios u ON g.IDUsuario = u.IDUsuario
                    WHERE 
                        u.IDUsuario = :IDUsuario
                    GROUP BY 
                        YEAR(g.Fecha), 
                        MONTH(g.Fecha)
                    ORDER BY 
                        Año, Mes";
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindParam(':IDUsuario', $IDUsuario, PDO::PARAM_INT);
            $stn->execute();
            return $stn->fetchAll();
        } catch (\Throwable $th) {
            return false;
        } finally {
            if (isset($conexion)) {
                unset($conexion);
            }
            if (isset($stn)) {
                unset($stn);
            }
        }
    }
}
