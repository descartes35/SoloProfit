<?php ob_start() ?>
<h2>Inicio de sesión</h2>
<br>

<form action="index.php?ctl=SesionInicio" method="post">
    <div class="mb-5 row">
        <label for="staticEmail" class="col-sm-2 col-form-label">Email</label>
        <div class="col-sm-10">
            <input type="email" name="email" class="form-control" id="staticEmail" placeholder="Introduce tu email" required>
        </div>
        <div class="error">
            <?php
            if (isset($_SESSION['errorCredenciales']['email'])) {
                echo "<p>" . htmlspecialchars($_SESSION['errorCredenciales']['email']) . "</p>";
            }
            ?>
        </div>
    </div>
    <div class="mb-5 row">
        <label for="inputPassword" class="col-sm-2 col-form-label">Password</label>
        <div class="col-sm-10">
            <input type="password" name="pwd" class="form-control" placeholder="Introduce tu contraseña" id="inputPassword" required>
        </div>
        <div class="error">
            <?php
            if (isset($_SESSION['errorCredenciales']['pwd'])) {
                echo "<p>" . htmlspecialchars($_SESSION['errorCredenciales']['pwd']) . "</p>";
            }
            ?>
        </div>
    </div>
    <div class="col-6">
        <button class="btn btn-success" type="submit">Enviar</button>
    </div>
</form>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../base.php'; ?>
