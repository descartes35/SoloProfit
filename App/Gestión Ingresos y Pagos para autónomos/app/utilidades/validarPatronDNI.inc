<?php
function validarDNI($dni)
{
    // La expresión regular verifica que haya exactamente 8 dígitos seguidos de una letra mayúscula
    $patron = '/^[0-9]{8}[A-Z]$/';

    // Retorna verdadero si el DNI cumple con el patrón
    if (preg_match($patron, $dni)) {
        return true;
    } else {
        return false;
    }
}
