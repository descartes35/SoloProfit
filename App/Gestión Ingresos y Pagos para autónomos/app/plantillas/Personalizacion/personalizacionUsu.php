<?php ob_start() ?>
<div class="container">
    <h2>Editar Perfil</h2>
    <form method="post">
        <!-- action="index.php?ctl=actualizarUsu" -->
        <div class="mb-3">
            <label for="nombre" class="form-label">Nombre</label>
            <input type="text" class="form-control" id="nombre" name="nombre" value="<?php echo $datosUsuario['Nombre']; ?>">
        </div>
        <div class="mb-3">
            <label for="apellidos" class="form-label">Apellidos</label>
            <input type="text" class="form-control" id="apellidos" name="apellidos" value="<?php echo $datosUsuario['Apellidos']; ?>">
        </div>
        <div class="mb-3">
            <label for="email" class="form-label">Email</label>
            <input type="email" class="form-control" id="email" name="email" value="<?php echo $datosUsuario['Email']; ?>">
        </div>
        <div class="mb-3">
            <label for="contraseña" class="form-label">Contraseña</label>
            <input type="password" class="form-control" id="contraseña" name="contraseña" value="<?php echo $datosUsuario['Email']; ?>">
        </div>
        <div class="mb-3">
            <label for="direccion" class="form-label">Dirección</label>
            <input type="text" class="form-control" id="direccion" name="direccion" value="<?php echo $datosUsuario['Direccion']; ?>">
        </div>
        <div class="mb-3">
            <label for="dni" class="form-label">DNI</label>
            <input type="text" class="form-control" id="dni" name="dni" value="<?php echo $datosUsuario['NIF']; ?>">
        </div>
        <div class="form-check mb-3">
            <input type="checkbox" class="form-check-input" id="modoOscuro" name="modoOscuro" <?php echo ($datosUsuario['ModoOscuro'] ? 'checked' : ''); ?>>
            <label class="form-check-label" for="modoOscuro">Modo Oscuro</label>
        </div>
        <button type="submit" class="btn btn-warning">Guardar Cambios</button>
    </form>
</div>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../base.php'; ?>