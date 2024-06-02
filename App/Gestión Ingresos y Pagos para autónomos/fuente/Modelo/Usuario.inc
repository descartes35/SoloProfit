<?php

class Usuario
{
    private $id;
    private $nombre;
    private $email;
    private $contraseña;
    private $direccion;

    public function __construct($nombre, $email, $contraseña, $direccion)
    {
        $this->nombre = $nombre;
        $this->email = $email;
        $this->contraseña = $contraseña;
        $this->direccion = $direccion;
    }

    // Métodos de acceso
    public function getId()
    {
        return $this->id;
    }

    public function getNombre()
    {
        return $this->nombre;
    }

    public function getEmail()
    {
        return $this->email;
    }

    public function getDireccion()
    {
        return $this->direccion;
    }

    // Métodos de validación
    public function validarEmail($email)
    {
        // Lógica de validación del correo electrónico
    }

    public function validarContraseña($contraseña)
    {
        // Lógica de validación de la contraseña
    }

    // Métodos de manipulación de datos
    public function guardar()
    {
        // Lógica para guardar el usuario en la base de datos
    }

    public function actualizar()
    {
        // Lógica para actualizar el usuario en la base de datos
    }

    public function eliminar()
    {
        // Lógica para eliminar el usuario de la base de datos
    }
}
