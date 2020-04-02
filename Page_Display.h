#ifndef PAGE_DISPLAY_H
#define PAGE_DISPLAY_H

const char PAGE_Display[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="/"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Display Settings</strong>
<hr>
<form action="" method="get">
<table border="0"  cellspacing="0" cellpadding="3" >
<tr><td align="right">Display mode:</td><td><input type="checkbox" id="displaymode" name="displaymode"></td></tr>
<tr><td align="right"> </td><td></td></tr>
<tr><td align="right">Select Color Set</td><td>
<select  id="colorset" name="colorset">
  <option value="0">Twenty-Two Colors of Maximum Contrast v1</option>
  <option value="1">Twenty-Two Colors of Maximum Contrast v2</option>
  <option value="2">List of 20 Simple, Distinct Colors</option>
  <option value="3">Selecting colors for statistical graphics</option>
  <option value="4">Generating Visually Distinct Colors</option>
  <option value="5">Visually Distinct Color Generator</option>
  <option value="6">FastLED HSV colors</option>
</select>
</td></tr>
<tr><td colspan="2" align="center"><input type="submit" style="width:150px" class="btn btn--m btn--blue" value="Save"></td></tr>
</table>
</form>
<script>
  
window.onload = function ()
{
  load("style.css","css", function() 
  {
    load("microajax.js","js", function() 
    {
        setValues("/admin/displayvalues");
    });
  });
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}

</script>
)=====";

void send_display_html()
{
	Serial.println("************************************");
	Serial.println(server.args());

	  if (server.args() > 0 )  // Save Settings
	  {
	    //String temp = "";
		config.DisplayMode = false;
	    for ( uint8_t i = 0; i < server.args(); i++ ) {
	      if (server.argName(i) == "displaymode") config.DisplayMode = true;
	      if (server.argName(i) == "colorset") config.ColorSet =  server.arg(i).toInt();
	    }

	    Serial.println(config.DisplayMode);
		Serial.print("ColorSet:");Serial.println(config.ColorSet);
	    WriteConfig();

	  }
	  server.send_P ( 200, "text/html", PAGE_Display );
	  Serial.println(__FUNCTION__);
}

void send_display_values_html()
{

  String values ="";
  values += "displaymode|" +  (String) (config.DisplayMode ? "checked" : "") + "|chk\n";
  values += "colorset|" + (String) config.ColorSet + "|input\n";
  Serial.println(values);
  server.send ( 200, "text/plain", values);
  Serial.println(__FUNCTION__);
  AdminTimeOutCounter=0;
}





#endif
