<?php
require_once __DIR__ . '/../../Core/ConexionBd.inc';
class GestionRepositorio
{
    //______________________________CREACIÓN______________________________________//
    //________________________________start________________//
    public function CrearCliente($idUsuario, $nombre, $email = "", $telefono = "", $direccion = "", $descripcion = ""): bool
    {
        $sql = "INSERT INTO dbo.Clientes (IDUsuario ,Nombre, Email, Telefono, Direccion, Descripcion)
         Values (:idUsuario, :nombre, :correo, :tlfn, :dirrecc, :descripcion);";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idUsuario", $idUsuario);
            $stn->bindValue(":nombre", $nombre);
            $stn->bindValue(":correo", $email);
            $stn->bindValue(":tlfn", $telefono);
            $stn->bindValue(":dirrecc", $direccion);
            $stn->bindValue(":descripcion", $descripcion);
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

    public function CrearProveedor($idUsuario, $nombre, $email = "", $telefono = "", $direccion = "", $descripcion = ""): bool
    {
        $sql = "INSERT INTO dbo.Proveedores (IDUsuario ,Nombre, Email, Telefono, Direccion, Descripcion)
         Values (:idUsuario, :nombre, :correo, :tlfn, :dirrecc, :descripcion);";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idUsuario", $idUsuario);
            $stn->bindValue(":nombre", $nombre);
            $stn->bindValue(":correo", $email);
            $stn->bindValue(":tlfn", $telefono);
            $stn->bindValue(":dirrecc", $direccion);
            $stn->bindValue(":descripcion", $descripcion);
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

    public function crearProyecto($idUsuario, $nombre, $descripcion, $fechaInicio, $fechaFin)
    {
        $sql = "INSERT INTO dbo.Proyectos(IDUsuario, Nombre, Descripcion, FechaInicio, FechaFin) 
        values (:idUsuario, :nombre, :descripcion, :FechaInicio, :FechaFin)";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idUsuario", $idUsuario);
            $stn->bindValue(":nombre", $nombre);
            $stn->bindValue(":descripcion", $descripcion);
            $stn->bindValue(":FechaInicio", $fechaInicio);
            $stn->bindValue(":FechaFin", $fechaFin);
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
    //________________________________end________________//
    //______________________________CREACIÓN______________________________________//
    // *********************************************************************************************//
    //______________________________VISUALIZACIÓN______________________________________//
    //________________________________start________________//
    public function ObtenerProveedoresByIdUsuario($idUsuario): array | bool
    {
        $sql = "select * from dbo.Proveedores where IDUsuario=:idUsuario";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idUsuario", $idUsuario);
            $stn->execute();

            $proveedores = [];
            while ($fila = $stn->fetch(PDO::FETCH_ASSOC)) {
                $proveedor = [];
                $proveedor['IDProveedor'] = $fila['IDProveedor'];
                $proveedor['IDUsuario'] = $fila['IDUsuario'];
                $proveedor['Nombre'] = $fila['Nombre'];
                $proveedor['Email'] = $fila['Email'];
                $proveedor['Telefono'] = $fila['Telefono'];
                $proveedor['Direccion'] = $fila['Direccion'];
                $proveedor['Descripcion'] = $fila['Descripcion'];
                $proveedores[] = $proveedor;
            }

            if (!empty($proveedores)) {
                return $proveedores;
            } else {
                return [];
            }
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

    public function ObtenerClientesByIdUsuario($idUsuario): array | bool
    {
        $sql = "select * from dbo.Clientes where IDUsuario=:idUsuario";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idUsuario", $idUsuario);
            $stn->execute();

            $clientes = [];
            while ($fila = $stn->fetch(PDO::FETCH_ASSOC)) {
                $cliente = [];
                $cliente['IDCliente'] = $fila['IDCliente'];
                $cliente['IDUsuario'] = $fila['IDUsuario'];
                $cliente['Nombre'] = $fila['Nombre'];
                $cliente['Email'] = $fila['Email'];
                $cliente['Telefono'] = $fila['Telefono'];
                $cliente['Direccion'] = $fila['Direccion'];
                $cliente['Descripcion'] = $fila['Descripcion'];
                $clientes[] = $cliente;
            }

            if (!empty($clientes)) {
                return $clientes;
            } else {
                return [];
            }
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

    public function ObtenerProyectosByIdUsuario($idUsuario): array | bool
    {
        $sql = "SELECT * FROM dbo.Proyectos WHERE IDUsuario = :idUsuario";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idUsuario", $idUsuario);
            $stn->execute();

            $proyectos = [];
            while ($fila = $stn->fetch(PDO::FETCH_ASSOC)) {
                $proyecto = [];
                $proyecto['IDProyecto'] = $fila['IDProyecto'];
                $proyecto['IDUsuario'] = $fila['IDUsuario'];
                $proyecto['Nombre'] = $fila['Nombre'];
                $proyecto['Descripcion'] = $fila['Descripcion'];
                $proyecto['FechaInicio'] = $fila['FechaInicio'];
                $proyecto['FechaFin'] = $fila['FechaFin'];
                $proyectos[] = $proyecto;
            }

            if (!empty($proyectos)) {
                return $proyectos;
            } else {
                return [];
            }
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

    public function obtenerClienteById($idCliente)
    {
        $sql = "SELECT * FROM Clientes WHERE IDCliente = :idCliente";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idCliente", $idCliente);
            $stn->execute();

            $cliente = $stn->fetch(PDO::FETCH_ASSOC);
            return $cliente ?: false;
        } catch (\Throwable $th) {
            // Manejo de errores
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

    public function obtenerProveedorById($idProveedor)
    {
        $sql = "SELECT * FROM Proveedores WHERE IDProveedor = :idProveedor";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idProveedor", $idProveedor);
            $stn->execute();

            $proveedor = $stn->fetch(PDO::FETCH_ASSOC);
            return $proveedor ?: false;
        } catch (\Throwable $th) {
            // Manejo de errores
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

    public function obtenerProyectoById($idProyecto)
    {
        $sql = "SELECT * FROM Proyectos WHERE IDProyecto = :idProyecto";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idProyecto", $idProyecto);
            $stn->execute();

            $proyecto = $stn->fetch(PDO::FETCH_ASSOC);
            return $proyecto ?: false;
        } catch (\Throwable $th) {
            // Manejo de errores
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
    //________________________________end________________//
    //______________________________VISUALIZACIÓN______________________________________//
    // *********************************************************************************************//
    //______________________________ELIMINACIÓN______________________________________//
    //________________________________start________________//
    public function borrarCliente($idCliente)
    {
        $sql = "DELETE FROM Clientes WHERE IDCliente = :idCliente";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idCliente", $idCliente);
            $resultado = $stn->execute();

            return $resultado;
        } catch (\Throwable $th) {
            // Manejo de errores
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

    public function borrarProveedor($idProveedor)
    {
        $sql = "DELETE FROM Proveedores WHERE IDProveedor = :idProveedor";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idProveedor", $idProveedor);
            $resultado = $stn->execute();

            return $resultado;
        } catch (\Throwable $th) {
            // Manejo de errores
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

    public function borrarProyecto($idProyecto)
    {
        $sql = "DELETE FROM Proyectos WHERE IDProyecto = :idProyecto";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idProyecto", $idProyecto);
            $resultado = $stn->execute();

            return $resultado;
        } catch (\Throwable $th) {
            // Manejo de errores
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
    //________________________________end________________//
    //______________________________ELIMINACIÓN______________________________________//
    // *********************************************************************************************//
    //______________________________EDICIÓN______________________________________//
    //________________________________start________________//
    public function actualizarCliente($idCliente, $nombre, $email, $telefono, $direccion, $descripcion)
    {
        $sql = "UPDATE Clientes 
                SET Nombre = :nombre, 
                    Email = :email, 
                    Telefono = :telefono, 
                    Direccion = :direccion, 
                    Descripcion = :descripcion
                WHERE IDCliente = :idCliente";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idCliente", $idCliente);
            $stn->bindValue(":nombre", $nombre);
            $stn->bindValue(":email", $email);
            $stn->bindValue(":telefono", $telefono);
            $stn->bindValue(":direccion", $direccion);
            $stn->bindValue(":descripcion", $descripcion);
            $resultado = $stn->execute();

            return $resultado;
        } catch (\Throwable $th) {
            // Manejo de errores
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
    public function actualizarProveedor($idProveedor, $nombre, $email, $telefono, $direccion, $descripcion)
    {
        $sql = "UPDATE Proveedores 
                SET Nombre = :nombre, 
                    Email = :email, 
                    Telefono = :telefono, 
                    Direccion = :direccion, 
                    Descripcion = :descripcion
                WHERE IDProveedor = :idProveedor";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idProveedor", $idProveedor);
            $stn->bindValue(":nombre", $nombre);
            $stn->bindValue(":email", $email);
            $stn->bindValue(":telefono", $telefono);
            $stn->bindValue(":direccion", $direccion);
            $stn->bindValue(":descripcion", $descripcion);
            $resultado = $stn->execute();

            return $resultado;
        } catch (\Throwable $th) {
            // Manejo de errores
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
    public function actualizarProyecto($idProyecto, $nombre, $descripcion, $fechaInicio, $fechaFin)
    {
        $sql = "UPDATE Proyectos 
                SET Nombre = :nombre, 
                    Descripcion = :descripcion, 
                    FechaInicio = :fechaInicio, 
                    FechaFin = :fechaFin
                WHERE IDProyecto = :idProyecto";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idProyecto", $idProyecto);
            $stn->bindValue(":nombre", $nombre);
            $stn->bindValue(":descripcion", $descripcion);
            $stn->bindValue(":fechaInicio", $fechaInicio);
            $stn->bindValue(":fechaFin", $fechaFin);
            $resultado = $stn->execute();

            return $resultado;
        } catch (\Throwable $th) {
            // Manejo de errores
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
    //________________________________end________________//
    //______________________________EDICIÓN______________________________________//
}
