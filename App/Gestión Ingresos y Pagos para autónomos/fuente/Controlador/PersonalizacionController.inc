<?php
class PersonalizacionController
{
    public function editarUsuario()
    {
        require_once __DIR__ . '/../Repositorio/UsuarioRepositorio.inc';

        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $idUsuario = $_SESSION['IDUsuario'];
            $nombre = $_POST['nombre'];
            $apellidos = $_POST['apellidos'];
            $email = $_POST['email'];
            $contraseña = $_POST['contraseña'];
            $direccion = $_POST['direccion'];
            $dni = $_POST['dni'];
            $modoOscuro = isset($_POST['modoOscuro']) ? 1 : 0;

            $usuarioRepo = new UsuarioRepositorio();

            // Obtener la contraseña actual del usuario
            $datosUsuario = $usuarioRepo->getDatosUsuarioById($idUsuario);

            // Si el campo de contraseña no está vacío, hashearla
            if (!empty($contraseña)) {
                $hashContraseña = password_hash($contraseña, PASSWORD_DEFAULT);
            } else {
                // Si está vacío, mantener la contraseña actual
                $hashContraseña = $datosUsuario['Contraseña'];
            }

            if ($usuarioRepo->actualizarUsuario($idUsuario, $nombre, $apellidos, $email, $hashContraseña, $direccion, $dni, $modoOscuro)) {
                // Actualizar la variable de sesión después de la actualización exitosa
                $_SESSION['ModoOscuro'] = $modoOscuro;
                // Redirigir a la misma página para aplicar los cambios instantáneamente
                header('Location: ' . $_SERVER['REQUEST_URI']);
                exit();
            }
        } else {
            // Obtener los datos del usuario para mostrarlos en el formulario
            $datosUsuario = (new UsuarioRepositorio())->getDatosUsuarioByCorreo($_SESSION['Email']);
            require_once __DIR__ . '/../../app/plantillas/Personalizacion/personalizacionUsu.php';
        }
    }
}
