<?php

class InventarioRepositorio
{
    public function obtenerArticulosByIdUsuario($idUsuario, $tipo): array
    {
        $sql = "SELECT * FROM dbo.Inventario WHERE IDUsuario=:idUsuario AND Tipo=:tipo";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idUsuario", $idUsuario);
            $stn->bindValue(":tipo", $tipo);
            $stn->execute();

            $articulos = [];
            while ($fila = $stn->fetch(PDO::FETCH_ASSOC)) {
                $articulos[] = $fila;
            }

            return $articulos;
        } catch (\Throwable $th) {
            // echo $th->getMessage(); 
            return [];
        } finally {
            if (isset($conexion)) {
                unset($conexion);
            }
            if (isset($stn)) {
                unset($stn);
            }
        }
    }

    public function obtenerArticulosByIdUsuarioSinTipo($idUsuario): array
    {
        $sql = "SELECT * FROM dbo.Inventario WHERE IDUsuario=:idUsuario";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idUsuario", $idUsuario);
            $stn->execute();

            $articulos = [];
            while ($fila = $stn->fetch(PDO::FETCH_ASSOC)) {
                $articulos[] = $fila;
            }

            return $articulos;
        } catch (\Throwable $th) {
            // echo $th->getMessage(); 
            return [];
        } finally {
            if (isset($conexion)) {
                unset($conexion);
            }
            if (isset($stn)) {
                unset($stn);
            }
        }
    }

    public function obtenerArticuloPorId($id)
    {
        $sql = "SELECT * FROM dbo.Inventario WHERE IDArticulo=:id";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":id", $id);
            $stn->execute();

            return $stn->fetch(PDO::FETCH_ASSOC);
        } catch (\Throwable $th) {
            // echo $th->getMessage(); 
            return null;
        } finally {
            if (isset($conexion)) {
                unset($conexion);
            }
            if (isset($stn)) {
                unset($stn);
            }
        }
    }

    public function agregarArticulo($idUsuario, $nombre, $descripcion, $precioCompra, $precioVenta, $stock, $categoria, $tipo): bool
    {
        $sql = "INSERT INTO dbo.Inventario (IDUsuario, Nombre, Descripcion, PrecioCompra, PrecioVenta, Stock, FechaRegistro, Categoria, Tipo)
                VALUES (:idUsuario, :nombre, :descripcion, :precioCompra, :precioVenta, :stock, GETDATE(), :categoria, :tipo)";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idUsuario", $idUsuario);
            $stn->bindValue(":nombre", $nombre);
            $stn->bindValue(":descripcion", $descripcion);
            $stn->bindValue(":precioCompra", $precioCompra);
            $stn->bindValue(":precioVenta", $precioVenta);
            $stn->bindValue(":stock", $stock);
            $stn->bindValue(":categoria", ucfirst(strtolower($categoria)));
            $stn->bindValue(":tipo", $tipo);
            $stn->execute();

            return true;
        } catch (\Throwable $th) {
            // echo $th->getMessage(); 
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

    public function actualizarServicio($id, $nombre, $categoria, $descripcion, $fechaRegistro, $tipo): bool
    {
        $sql = "UPDATE dbo.Inventario 
                SET Nombre = :nombre, 
                    Categoria = :categoria, 
                    Descripcion = :descripcion, 
                    FechaRegistro = CONVERT(DATETIME, :fechaRegistro, 120), 
                    Tipo = :tipo 
                WHERE IDArticulo = :id AND Tipo = 'Servicio'";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":id", $id);
            $stn->bindValue(":nombre", $nombre);
            $stn->bindValue(":categoria", $categoria);
            $stn->bindValue(":descripcion", $descripcion);
            $stn->bindValue(":fechaRegistro", $fechaRegistro);
            $stn->bindValue(":tipo", $tipo);
            $stn->execute();

            return true;
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



    public function borrarServicio($id): bool
    {
        $sql = "DELETE FROM dbo.Inventario WHERE IDArticulo = :id AND Tipo = 'Servicio'";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":id", $id);
            $stn->execute();

            return true;
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

    public function actualizarProducto($id, $nombre, $categoria, $descripcion, $precioCompra, $precioVenta, $stock): bool
    {
        $sql = "UPDATE dbo.Inventario SET Nombre = :nombre, Categoria = :categoria, Descripcion = :descripcion, 
                PrecioCompra = :precioCompra, PrecioVenta = :precioVenta, Stock = :stock WHERE IDArticulo = :id AND Tipo = 'Producto'";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":id", $id);
            $stn->bindValue(":nombre", $nombre);
            $stn->bindValue(":categoria", $categoria);
            $stn->bindValue(":descripcion", $descripcion);
            $stn->bindValue(":precioCompra", $precioCompra);
            $stn->bindValue(":precioVenta", $precioVenta);
            $stn->bindValue(":stock", $stock);
            $stn->execute();

            return true;
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

    public function borrarProducto($id): bool
    {
        $sql = "DELETE FROM dbo.Inventario WHERE IDArticulo = :id AND Tipo = 'Producto'";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":id", $id);
            $stn->execute();

            return true;
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
