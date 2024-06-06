<?php
class CitasRepositorio
{
    public function obtenerCitasByIdUsuario($idUsuario): array
    {
        $sql = "SELECT * FROM dbo.Citas WHERE IDUsuario=:idUsuario";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idUsuario", $idUsuario);
            $stn->execute();

            $citas = [];
            while ($fila = $stn->fetch(PDO::FETCH_ASSOC)) {
                $citas[] = $fila;
            }

            return $citas;
        } catch (\Throwable $th) {
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

    public function agregarCita($idUsuario, $fechaHora, $descripcion): bool
    {
        // Formatear la fecha y hora en el formato adecuado para SQL Server
        $fechaHoraFormateada = date('Y-m-d H:i:s', strtotime($fechaHora));

        $sql = "INSERT INTO dbo.Citas (IDUsuario, IDCliente, FechaHora, Descripcion)
                VALUES (:idUsuario, 1, CONVERT(datetime, :fechaHora, 120), :descripcion)";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idUsuario", $idUsuario);
            $stn->bindValue(":fechaHora", $fechaHoraFormateada);
            $stn->bindValue(":descripcion", $descripcion);
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


    public function borrarCita($id): bool
    {
        $sql = "DELETE FROM dbo.Citas WHERE IDCita = :id";

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
    public function obtenerCitaPorId($idCita)
    {
        $sql = "SELECT * FROM dbo.Citas WHERE IDCita = :idCita";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idCita", $idCita);
            $stn->execute();

            return $stn->fetch(PDO::FETCH_ASSOC);
        } catch (\Throwable $th) {
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

    public function editarCita($idCita, $fechaHora, $descripcion): bool
    {
        $fechaHoraFormateada = date('Y-m-d H:i:s', strtotime($fechaHora));

        $sql = "UPDATE dbo.Citas SET FechaHora = CONVERT(datetime, :fechaHora, 120), Descripcion = :descripcion WHERE IDCita = :idCita";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":fechaHora", $fechaHoraFormateada);
            $stn->bindValue(":descripcion", $descripcion);
            $stn->bindValue(":idCita", $idCita);
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
