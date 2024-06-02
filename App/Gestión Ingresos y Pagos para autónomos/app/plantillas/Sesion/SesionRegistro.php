<?php ob_start() ?>
<?php
// if (isset($_SESSION['errorCredenciales'])) {
//     var_dump($_SESSION['errorCredenciales']);
// }
?>
<div class="container">
    <h2 class="">Registrarse</h2>
    <form class="row g-3 needs-validation" action="index.php?ctl=registrarUsuario" method="post">
        <div class="col-md-4 position-relative">
            <label for="nombreUsu" class="form-label">Nombre</label>
            <input required name="nombre" type="text" class="form-control" id="nombreUsu" placeholder="Introduce tu nombre" value=<?php if (isset($_SESSION['nombre'])) {
                                                                                                                                        echo ($_SESSION['nombre']);
                                                                                                                                    } ?>>
            <div class="error">
                <?php
                if (isset($_SESSION['errorCredenciales']['nombre'])) {
                    echo ("<p>" . $_SESSION['errorCredenciales']['nombre'] . "<p>");
                }
                ?>
            </div>
        </div>
        <div class="col-md-4 position-relative">
            <label for="apellidoUsu" class="form-label">Apellido</label>
            <input required name="apellido" type="text" class="form-control" id="apellidoUsu" placeholder="Introduce tu apellido" value=<?php if (isset($_SESSION['apellido'])) {
                                                                                                                                            echo ($_SESSION['apellido']);
                                                                                                                                        } ?>>
            <div class="error">
                <?php
                if (isset($_SESSION['errorCredenciales']['apellido'])) {
                    echo ("<p>" . $_SESSION['errorCredenciales']['apellido'] . "<p>");
                }
                ?>
            </div>
        </div>
        <div class="col-md-4 position-relative">
            <label for="emailUsu" class="form-label">Correo electrónico</label>
            <div class="input-group has-validation">
                <span class="input-group-text" id="emailUsu">@</span>
                <input required name="email" type="text" class="form-control" placeholder="Introduce tu email" aria-describedby="validationTooltipUsernamePrepend" value=<?php if (isset($_SESSION['email'])) {
                                                                                                                                                                                echo ($_SESSION['email']);
                                                                                                                                                                            } ?>>
                <div class="error">
                    <?php
                    if (isset($_SESSION['errorCredenciales']['email'])) {
                        echo ("<p>" . $_SESSION['errorCredenciales']['email'] . "<p>");
                    }
                    ?>
                </div>
            </div>
        </div>
        <div class="col-md-6 position-relative">
            <label for="pwdUsu" class="form-label">Contraseña</label>
            <input required name="pwd" type="password" class="form-control" id="pwdUsu" placeholder="Introduce tu contraseña, min. 8 carácteres (incluido un signo)" value=<?php if (isset($_SESSION['pwd'])) {
                                                                                                                                                                            echo ($_SESSION['pwd']);
                                                                                                                                                                        } ?>>
            <div class="error">
                <?php
                if (isset($_SESSION['errorCredenciales']['pwd'])) {
                    echo ("<p>" . $_SESSION['errorCredenciales']['pwd'] . "<p>");
                }
                ?>
            </div>
        </div>
        <div class="col-md-3 position-relative">
            <label for="provinciaUsu" class="form-label">Provincia</label>
            <select requiredt class="form-select" name="provincia" id="provinciaUsu" value=<?php if (isset($_SESSION['provincia'])) {
                                                                                                echo ($_SESSION['provincia']);
                                                                                            } ?>>
                <option selected disabled value="">Elija una...</option>
                <option value="Álava">Álava</option>
                <option value="Albacete">Albacete</option>
                <option value="Alicante">Alicante</option>
                <option value="Almería">Almería</option>
                <option value="Asturias">Asturias</option>
                <option value="Ávila">Ávila</option>
                <option value="Badajoz">Badajoz</option>
                <option value="Baleares">Baleares</option>
                <option value="Barcelona">Barcelona</option>
                <option value="Burgos">Burgos</option>
                <option value="Cáceres">Cáceres</option>
                <option value="Cádiz">Cádiz</option>
                <option value="Cantabria">Cantabria</option>
                <option value="Castellón">Castellón</option>
                <option value="Ciudad Real">Ciudad Real</option>
                <option value="Córdoba">Córdoba</option>
                <option value="Cuenca">Cuenca</option>
                <option value="Gerona">Gerona</option>
                <option value="Granada">Granada</option>
                <option value="Guadalajara">Guadalajara</option>
                <option value="Guipúzcoa">Guipúzcoa</option>
                <option value="Huelva">Huelva</option>
                <option value="Huesca">Huesca</option>
                <option value="Jaén">Jaén</option>
                <option value="La Coruña">La Coruña</option>
                <option value="La Rioja">La Rioja</option>
                <option value="Las Palmas">Las Palmas</option>
                <option value="León">León</option>
                <option value="Lérida">Lérida</option>
                <option value="Lugo">Lugo</option>
                <option value="Madrid">Madrid</option>
                <option value="Málaga">Málaga</option>
                <option value="Murcia">Murcia</option>
                <option value="Navarra">Navarra</option>
                <option value="Orense">Orense</option>
                <option value="Palencia">Palencia</option>
                <option value="Pontevedra">Pontevedra</option>
                <option value="Salamanca">Salamanca</option>
                <option value="Segovia">Segovia</option>
                <option value="Sevilla">Sevilla</option>
                <option value="Soria">Soria</option>
                <option value="Tarragona">Tarragona</option>
                <option value="Tenerife">Tenerife</option>
                <option value="Teruel">Teruel</option>
                <option value="Toledo">Toledo</option>
                <option value="Valencia">Valencia</option>
                <option value="Valladolid">Valladolid</option>
                <option value="Vizcaya">Vizcaya</option>
                <option value="Zamora">Zamora</option>
                <option value="Zaragoza">Zaragoza</option>
            </select>
            <div class="error">
                <?php
                if (isset($_SESSION['errorCredenciales']['provincia'])) {
                    echo ("<p>" . $_SESSION['errorCredenciales']['provincia'] . "<p>");
                }
                ?>
            </div>
        </div>
        <div class="col-md-3 position-relative">
            <label for="cpUsu" class="form-label">Código postal</label>
            <input required name="cp" type="text" class="form-control" id="cpUsu" placeholder="Introduce tu código postal (Ej 36001:)" value=<?php if (isset($_SESSION['cp'])) {
                                                                                                                                                    echo ($_SESSION['cp']);
                                                                                                                                                } ?>>
            <div class="error">
                <?php
                if (isset($_SESSION['errorCredenciales']['cp'])) {
                    echo ("<p>" . $_SESSION['errorCredenciales']['cp'] . "<p>");
                }
                ?>
            </div>
        </div>
        <div class="col-md-3 position-relative">
            <label for="dniUsu" class="form-label">DNI/NIF</label>
            <input required name="dni" type="text" class="form-control" id="dniUsu" placeholder="Introduce un documento de identificación (Ej:AAA123456A)" value=<?php if (isset($_SESSION['dni'])) {
                                                                                                                                                                        echo ($_SESSION['dni']);
                                                                                                                                                                    } ?>>
            <div class="error">
                <?php
                if (isset($_SESSION['errorCredenciales']['dni'])) {
                    echo ("<p>" . $_SESSION['errorCredenciales']['dni'] . "<p>");
                }
                ?>
            </div>
        </div>
        <div class="col-12">
            <button class="btn btn-success" type="submit">Enviar</button>
        </div>
    </form>
</div>
<?php $contenido = ob_get_clean() ?>
<?php include_once __DIR__ . '/../base.php' ?>