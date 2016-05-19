<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Stock"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a stock name");
        }

        // query database for user
        $stock = lookup($_POST["symbol"]);

        // if we found user, check password
        if (count($stock) == 3)
        {

            render("quote.php", ["symbol" => $stock["symbol"], "name" => $stock["name"], "price" => $stock["price"]]);
        }
        // else apologize
        else
            apologize("Invalid stock input");
    }

?>
