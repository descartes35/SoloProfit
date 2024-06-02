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
            $hashContraseña = password_hash($contraseña, PASSWORD_DEFAULT);
            $direccion = $_POST['direccion'];
            $dni = $_POST['dni'];
            $modoOscuro = isset($_POST['modoOscuro']) ? 1 : 0; // Si el checkbox está marcado, modo oscuro es 1, de lo contrario es 0

            $usuarioRepo = new UsuarioRepositorio();
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

    public function editarVisualizacion()
    {
    }
}
