<?php ob_start() ?>
<h3>Gestión-><a class="enlaceVerde" href="index.php?ctl=ClientesInicio">Clientes</a>->Añadir</h3>
<hr>
<form class="row g-3" method="post">
    <div class="col-md-6">
        <label for="Nombre" class="form-label">Nombre:</label>
        <input type="text" class="form-control" id="Nombre" name="Nombre" required>
    </div>
    <div class="error">
        <?php
        if (isset($_SESSION['errorNombreCli'])) {
        ?>
            <p>El nombre es obligatorio</p>
        <?php
        }
        ?>
    </div>
    <div class="col-md-6">
        <label for="Email" class="form-label">Email:</label>
        <input type="email" class="form-control" id="Email" name="Email">
    </div>
    <div class="col-md-6">
        <label for="Telefono" class="form-label">Teléfono:</label>
        <input type="tel" class="form-control" id="Telefono" name="Telefono">
    </div>
    <div class="col-md-6">
        <label for="Direccion" class="form-label">Dirección:</label>
        <input type="text" class="form-control" id="Direccion" name="Direccion">
    </div>
    <div class="col-12">
        <label for="Descripcion" class="form-label">Descripción:</label>
        <textarea class="form-control" id="Descripcion" name="Descripcion" rows="3"></textarea>
    </div>
    <div class="col-12 text-center">
        <br>
        <button type="submit" class="btn btn-warning">Añadir cliente</button>
    </div>
</form>

<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>