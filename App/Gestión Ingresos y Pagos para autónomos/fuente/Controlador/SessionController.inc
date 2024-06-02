<?php
require_once __DIR__ . '/../../app/utilidades/validarPatronContrasenia.inc';
require_once __DIR__ . '/../../app/utilidades/validarPatronDNI.inc';
require_once __DIR__ . '/../../app/utilidades/sanea.inc';
require_once __DIR__ . '/../../fuente/Repositorio/UsuarioRepositorio.inc';
class SessionController
{
    public function iniciarSesion()
    {
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            if (empty($_POST['email']) || !filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)) {
                $_SESSION['errorCredenciales']['email'] = "Introduzca un correo válido por favor.";
            } elseif (!empty($_POST['pwd'])) {
                $usuarioRepo = new UsuarioRepositorio();
                $usuario = $usuarioRepo->getDatosUsuarioByCorreo($_POST['email']);
                if ($usuario && password_verify($_POST['pwd'], $usuario['Contraseña'])) {
                    // Limpia errores previos
                    unset($_SESSION['errorCredenciales']);
                    $_SESSION['IDUsuario'] = $usuario['IDUsuario'];
                    $_SESSION['Nombre'] = $usuario['Nombre'];
                    $_SESSION['Apellidos'] = $usuario['Apellidos'];
                    $_SESSION['Email'] = $usuario['Email'];
                    $_SESSION['Direccion'] = $usuario['Direccion'];
                    $_SESSION['NIF'] = $usuario['NIF'];
                    $_SESSION['ModoOscuro'] = $usuario['ModoOscuro'];
                    $_SESSION['sesionIniciada'] = true;
                    header('Location: index.php?ctl=inicio');
                    exit();
                } else {
                    $_SESSION['errorCredenciales']['general'] = "El correo o la contraseña no son correctos.";
                }
            } else {
                $_SESSION['errorCredenciales']['pwd'] = "Introduzca la contraseña.";
            }

            header('Location: index.php?ctl=SesionInicio');
            exit();
        }

        require __DIR__ . '/../../app/plantillas/Sesion/SesionInicio.php';
    }


    // ====================================REGISTRO====================================//
    // ========================================start====================//
    public function registrarUsuario()
    {
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $usuarioRepo = new UsuarioRepositorio();
            $errorCredenciales = [];

            // Inicialización de errores
            if (isset($_SESSION['errorCredenciales'])) {
                unset($_SESSION['errorCredenciales']);
            }

            // Validación de nombre
            if (empty($_POST['nombre']) || strlen($_POST['nombre']) < 3) {
                $errorCredenciales['nombre'] = "Introduzca un nombre con una longitud de al menos tres caracteres por favor.";
            }

            // Validación de apellido
            if (empty($_POST['apellido']) || strlen($_POST['apellido']) < 3) {
                $errorCredenciales['apellido'] = "Introduzca un apellido con una longitud de al menos tres caracteres por favor.";
            }

            // Validación de email
            if (empty($_POST['email']) || !filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)) {
                $errorCredenciales['email'] = "Introduzca un correo válido por favor.";
            } else {
                if ($usuarioRepo->getDatosUsuarioByCorreo($_POST['email'])) { // Si el correo existe en la BBDD
                    $errorCredenciales['email'] = "Este correo ya está registrado.";
                }
            }

            // Validación de contraseña
            if (empty($_POST['pwd']) || !validarContrasena($_POST['pwd'])) {
                $errorCredenciales['pwd'] = "La contraseña debe tener al menos 8 caracteres con un signo.";
            }

            // Validación de provincia
            if (empty($_POST['provincia'])) {
                $errorCredenciales['provincia'] = "Seleccione una provincia por favor.";
            }

            // Validación de código postal
            if (empty($_POST['cp']) || $_POST['cp'] < 01001 || $_POST['cp'] > 52006) {
                $errorCredenciales['cp'] = "Introduzca un Código Postal válido por favor.";
            }

            // Validación de DNI
            if (empty($_POST['dni']) || !validarDNI($_POST['dni'])) {
                $errorCredenciales['dni'] = "El DNI debe seguir un patrón 00000000A.";
            }

            if (empty($errorCredenciales)) { // Si no hay errores
                $direccion = $_POST['cp'] . ", " . $_POST['provincia'];
                $idUsuario = $usuarioRepo->crearUsuario($_POST['nombre'], $_POST['apellido'], $_POST['email'], password_hash($_POST['pwd'], PASSWORD_DEFAULT), $direccion, $_POST['dni']);

                if ($idUsuario !== false) {
                    $_SESSION['Nombre'] = $_POST['nombre'];
                    $_SESSION['Apellido'] = $_POST['apellido'];
                    $_SESSION['Email'] = $_POST['email'];
                    $_SESSION['Direccion'] = $direccion;
                    $_SESSION['NIF'] = $_POST['dni'];
                    $_SESSION['IDUsuario'] = $idUsuario; // Usar el ID de usuario devuelto por la función crearUsuario
                    $_SESSION['ModoOscuro'] = 0; // Usar el ID de usuario devuelto por la función crearUsuario
                    $_SESSION['sesionIniciada'] = true;

                    header('Location: index.php?ctl=inicio');
                    exit();
                } else {
                    echo ("<p>" . "Ha ocurrido un error en el registro" . "<p>");
                }
            } else {
                $_SESSION['errorCredenciales'] = $errorCredenciales;
                header('Location: index.php?ctl=SesionRegsitro');
                exit();
            }
        }

        require __DIR__ . '/../../app/plantillas/Sesion/SesionRegistro.php';
    }



    public function cerrarSesion()
    {
        $_SESSION = [];
        header('Location: index.php?ctl=inicio');
        exit();
        // require __DIR__ . '/../../app/plantillas/Sesion/SesionRegistro.php';
    }
    // ========================================end====================//
    // ====================================REGISTRO====================================//
}
