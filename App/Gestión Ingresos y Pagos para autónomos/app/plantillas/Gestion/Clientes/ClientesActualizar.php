<?php ob_start() ?>
<h3>Gestión-><a class="enlaceVerde" href="index.php?ctl=ClientesInicio">Clientes</a>->Editar</h3>
<hr>
<form method="post" action="index.php?ctl=ClientesEditar&id=<?php echo htmlspecialchars($cliente['IDCliente']); ?>">
    <div class="mb-3">
        <label for="nombre" class="form-label">Nombre</label>
        <input type="text" class="form-control" id="nombre" name="nombre" value="<?php echo htmlspecialchars($cliente['Nombre']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="email" class="form-label">Email</label>
        <input type="email" class="form-control" id="email" name="email" value="<?php echo htmlspecialchars($cliente['Email']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="telefono" class="form-label">Teléfono</label>
        <input type="text" class="form-control" id="telefono" name="telefono" value="<?php echo htmlspecialchars($cliente['Telefono']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="direccion" class="form-label">Dirección</label>
        <input type="text" class="form-control" id="direccion" name="direccion" value="<?php echo htmlspecialchars($cliente['Direccion']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="descripcion" class="form-label">Descripción</label>
        <textarea class="form-control" id="descripcion" name="descripcion" rows="3" required><?php echo htmlspecialchars($cliente['Descripcion']); ?></textarea>
    </div>
    <button type="submit" class="btn btn-primary">Actualizar</button>
</form>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>
