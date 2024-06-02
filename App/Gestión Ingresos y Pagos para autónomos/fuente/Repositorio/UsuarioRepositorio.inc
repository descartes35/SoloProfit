<?php
require_once __DIR__ . '/../../Core/ConexionBd.inc';
class UsuarioRepositorio
{

    public function getDatosUsuarioByCorreo($correo): array |bool
    {
        $sql = "SELECT *  FROM [dbo].[usuarios] WHERE Email = :correo";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":correo", $correo);
            $stn->execute();

            while ($fila = $stn->fetch(PDO::FETCH_ASSOC)) {
                $usuario = [];
                $usuario['IDUsuario'] = $fila['IDUsuario'];
                $usuario['Nombre'] = $fila['Nombre'];
                $usuario['Apellidos'] = $fila['Apellidos'];
                $usuario['Email'] = $fila['Email'];
                $usuario['Contraseña'] = $fila['Contraseña'];
                $usuario['Direccion'] = $fila['Direccion']; //Todo va junto aquí (Provincia, Cp)
                $usuario['NIF'] = $fila['NIF'];
                $usuario['ModoOscuro'] = $fila['ModoOscuro'];
                $usuario['PreferenciasContacto'] = $fila['PreferenciasContacto'];
            }

            if (!empty($usuario)) {
                return $usuario;
            } else {
                return false;
            }
        } catch (\Exception $th) {
            return false;
            $th->getMessage();
        } finally {
            if (isset($conexion)) {
                unset($conexion);
            }
            if (isset($stn)) {
                unset($stn);
            }
        }
    }

    public function crearUsuario($nombre, $apellidos, $email, $contraseña, $direccion, $dni): bool| int
    {
        $sql = "
        INSERT INTO Autonomos_DB.dbo.Usuarios 
        (Nombre, Apellidos, Email, Contraseña, FechaRegistro, Direccion, NIF) 
        VALUES (:nombre, :apellidos, :email, :pwd, GETDATE(), :direccion, :dni)
        ";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":nombre", $nombre);
            $stn->bindValue(":apellidos", $apellidos);
            $stn->bindValue(":email", $email);
            $stn->bindValue(":pwd", $contraseña);
            $stn->bindValue(":direccion", $direccion);
            $stn->bindValue(":dni", $dni);
            $stn->execute();

            $idUsuario = $conexion->lastInsertId();
            return $idUsuario;
        } catch (\Exception $th) {
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

    public function actualizarUsuario($idUsuario, $nombre, $apellidos, $email, $contraseña, $direccion, $dni, $modoOscuro): bool
    {
        $sql = "
        UPDATE [dbo].[usuarios] 
        SET Nombre = :nombre, Apellidos = :apellidos, Email = :email, Contraseña = :pwd, Direccion = :direccion, NIF = :dni, ModoOscuro = :modoOscuro 
        WHERE IDUsuario = :idUsuario
        ";

        try {
            $conexion = (new ConexionBd())->getConexion();
            $stn = $conexion->prepare($sql);
            $stn->bindValue(":idUsuario", $idUsuario);
            $stn->bindValue(":nombre", $nombre);
            $stn->bindValue(":apellidos", $apellidos);
            $stn->bindValue(":email", $email);
            $stn->bindValue(":pwd", $contraseña);
            $stn->bindValue(":direccion", $direccion);
            $stn->bindValue(":dni", $dni);
            $stn->bindValue(":modoOscuro", $modoOscuro);
            $stn->execute();

            return true;
        } catch (\Exception $th) {
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
