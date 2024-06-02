<?php
function validarContrasena($contrasena)
{
    // La expresión regular asegura al menos un signo y un total de al menos 8 caracteres
    $patron = '/^(?=.*[\W_]).{8,}$/';

    // Retorna verdadero si la contraseña cumple con el patrón
    if (preg_match($patron, $contrasena)) {
        return true;
    } else {
        return false;
    }
}
