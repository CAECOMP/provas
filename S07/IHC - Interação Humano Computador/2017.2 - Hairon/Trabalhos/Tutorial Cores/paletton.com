<!DOCTYPE HTML>
<html lang="en">
<head>
	<meta http-equiv="content-type" content="text/html; charset=utf-8">
	<!-- Enable IE9 Standards mode -->
	<meta http-equiv="X-UA-Compatible" content="IE=edge">

	<title>Paletton - The Color Scheme Designer</title>

	<meta name="description" content="In love with colors, since 2002. A designer tool for creating color combinations that work together well. Formerly known as Color Scheme Designer. Use the color wheel to create great color palettes.">
	<meta name="keywords" content="color, scheme, wheel, color wheel, theory, color theory, colorwheel, design, designer, palette, colorize, colorset, RYB, RGB, web, colors, webcolors, safecolors, blind, blindness, simulation, protanopy, protanopia, deuteranopy, deuteranopia, tritanopy, tritanopia, daltonism, live, preview, pixy, barvy, barevné, míchátko">

	<link rel="icon" type="image/png" sizes="16x16" href="img/favicon-16.png">
	<link rel="icon" type="image/png" sizes="32x32" href="img/favicon-32.png">
	<link rel="icon" type="image/png" sizes="128x128" href="img/favicon-128.png">
	<link rel="apple-touch-icon" type="image/png" sizes="128x128" href="img/favicon-128.png">
	<link rel="image_src" href="img/paletton-preview-20140414.png">

	<link rel="stylesheet" type="text/css" href="css/jqui/jquery-ui-1.10.4.custom.css">
	<link rel="stylesheet" type="text/css" href="css/css/default.css">


<script type="text/javascript">
// globals init
	var browserInfo = {
		isOpera: !!window.opera,
		adBlockActive: true
		};
	var ad_slots = {};
</script>

<!--[if lt IE 9]>
	<script type="text/javascript">
		browserInfo.isOldIE = true;
	</script>
	<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8/jquery.min.js"></script>
<![endif]-->
<!--[if (gte IE 9) | (!IE)]><!-->
	<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/2.1.0/jquery.min.js"></script>
	<script type="text/javascript" src="js/lib/jquery-ui-1.10.4.custom.min.js"></script>
	<script type="text/javascript" src="js/lib/jquery.observehashchange.js"></script>
	<script type="text/javascript" src="js/lib/jquery.cookie.js"></script>
	
<!--<![endif]-->

<!-- Load ads support -->
	<script type="text/javascript" src="js/ads.js"></script>

<!-- Load default language -->
	<script type="text/javascript" src="js/lang/en.js"></script>




	<script type="text/javascript" src="js/lib/require.js" data-main="js/app.compiled.js"></script>
<!-- 	<script type="text/javascript" src="js/lib/require.js" data-main="js/compiled.js/app.js"></script> -->




<script type="text/javascript">

	var addthis_config = {
		"data_track_addressbar": false,
		"data_track_clickback": false,
		"ui_click": true,
		"ui_use_css": true,
	//	"ui_language": --- set in app.core after language is loaded
		"services_exclude": "print",
		"data_ga_property": "UA-51179325-1",
		"data_ga_social": true
		};
</script>

<script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#asynx=1&pubid=ra-4fcbb0414b3d9e9d"></script>


</head>

<body>

	<div id="app">

<!--
		<div id="survey" style="display:none; position: absolute; left:0;top:0;bottom:0;right:0;z-index:9999999;background:rgba(0,0,0,0.85);color:#fff;padding:100px 50px;text-align:center;font-size: 24px;">
			<h2 style="font-size: 250%">Survey</h2>
			<p>Please help us make Paletton even better. Take this</p>
			<a style="font-size:150%;color:#ffc;" href="#" onclick="surveyOpen(); return false">1-minute Paletton Users Survey</a>
			<p>Thank you.</p>
			<p style="margin-top: 5em;font-size: 67%"><a href="#" onclick="surveyHide(); return false">No thanks, maybe next time.</a></p>
		</div>

<script type="text/javascript">
	var sc1 = $.cookie('Paletton'), sc2 = $.cookie('PalettonSurvey');
	if (sc1 && !sc2) {
		setTimeout(function(){
			$('#survey').fadeIn()
			}, 1500 )
		}
	function surveyOpen() {
		window.open('https://surveyplanet.com/5767f0a826f371f8547b73e1');
		$.cookie('PalettonSurvey',1,{ expires:90, path:'/' });
		surveyHide();
		}
	function surveyHide() {
		$('#survey').remove();
		}
</script>
-->

		<div id="header">

			<div class="inner">
				<div class="logo"></div>
				<div class="tbr">
					<div class="likes">
						<div class="likesbox">
							<a class="addthis_button_facebook_like at300b" fb:like:layout="button_count" addthis:url="http://paletton.com"></a>
							<a class="addthis_button_tweet at300b" addthis:url="http://paletton.com"></a>
							<a class="addthis_button_google_plusone at300b" g:plusone:size="medium" addthis:url="http://paletton.com"></a>
							<a class="addthis_counter addthis_pill_style at300b" addthis:url="http://paletton.com"></a>
						</div>
					</div>
					<div class="lang"></div>
					<div class="promo">
						<a class="box1" href="#"></a>
						<a class="box2" href="#"></a>
						<a class="box3" href="#"></a>
					</div>
				</div>

			</div>

		</div><!-- /header -->

		<div id="content">

		<!-- Onload tests -->

			<div id="passivecontent">
				<h1>Paletton, the color scheme designer</h1>
				<h4>In love with colors, since 2002.</h4>
				<ol class="toc">
					<li><a id="part-1" href="/index.html">Paletton application</a></li>
					<li><a id="part-2" href="/wiki/">Colorpedia</a></li>
					<li><a id="part-3" href="/wiki/index.php?title=Paletton_version_history">About Paletton</a></li>
				</ol>
				<p>
					Paletton.com is a designer color tool designed for creating color combinations that work together well. It uses classical color theory with ancient artistic RYB color wheel to design color palettes of one to four hues, each of five different shades. Various preview style can be chosen to test and view the colors in combinations, many examples are available to see the palette used in web site design, UI design or in a randomly drawn picture. Tartan fabric preview is alos available for those interested in textile and interior design.
				</p>
				<p>
					This palette tool uses various color models to combine adjacent colors and/or complementary colors to the main hue. Select models from monochromatic to triad or tetrad color sets, with or without a complement (the opposite hue), enjoy even the free-style mode. Play with palette brightness and saturation, select from predefined presets, or create random palettes. The unique vision simulation filter emulates the palette as seen by people with various vision weakness, color blindness, various variants of daltonism (protanopy, deuteranopy, tritanopy, protanomaly, deuteranomaly, tritanomaly, dyschromatopsia or achromatopsia), as well as several gamma simulations (simulation of too bright display or too dark print), desaturation, grayscale conversion or webcolors (the legacy 216-color palette). The palette can be exported in many various formats (HTML, CSS, LESS, XML, text, PNG image, Photoshop ACO swatch palette or Gimp GPL palette format) to colorize your artwork. Check color contrast of all color pairs used in the palette and test if the color contrast fits WCAG requirements. More info about colors in the <a href="/wiki/">Colorpedia</a>.
				</p>
				<p>
					Paletton is the successor of the previous <a href="http://colorschemedesigner.com/csd-3.5/">Color Scheme Designer 3</a> application, used by almost 20 milion visitors since 2009 (while the first version was published in 2002), both professional designers and amateurs interested in design, mobile or desktop application design or web design, interior design, fashion or home improvement and make-overs. Complete <a href="/wiki/index.php?title=Paletton_version_history">Paletton history in Colorpedia</a>.
				</p>
			</div>

			<div id="jstest">
				No Javascript detected. Javascript is required for this application.
			</div>
			<script type="text/javascript">
				var e = document.getElementById('passivecontent');
				e.style.display = 'none';
				e = document.getElementById('jstest');
				e.innerHTML = '';
				e.className = 'loading';
			</script>
			<div id="csstest" style="display:none"></div>

		<!-- /tests -->

		</div><!-- /content -->

		<div id="footer">

			<p class="copy" style="display: none">
				© Paletton.com <small>by <a href="http://pixy.cz/index-en.html">Petr Staníček</a></small>
			</p>
			<p class="copy-ad">
				Wellstyled UX blog: <a href="http://wellstyled.com/en/ux-grid-preset-filtering/">Large tables filtering using presets</a>
			</p>
			<p>
				<span class="versions"></span>
				   •   
				<span class="contact"></span>
			</p>
			<p>
				My latest web design book: <a href="http://pixy.cz/kniha-dobrydesigner/">Petr Staníček: Dobrý designer to všechno ví!</a> (A Good Designer Knows All Of It!) (Czech only yet.)
			</p>

		</div><!-- /footer -->



<!-- ###################### -->


	<!-- Ad blocks -->



		<div class="reklambox reklambox-top" id="reklambox-top-left">		<!-- Ad block TOP LEFT box -->

			<a class="wix-box" href="http://www.wix.com/eteamhtml/900_create?utm_source=media_buying&utm_medium=paid_referral&utm_campaign=ma_paletton.com&experiment_id=paletton.com^top^textlink-cfswg_900_create"></a> 

		</div>




		<div class="reklambox w160" id="reklambox-col-left">		<!-- Ad block LEFT column -->

<script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
<!-- Paletton wide col 160 -->
<ins class="adsbygoogle"
     style="display:inline-block;width:160px;height:600px"
     data-ad-client="ca-pub-0771264873734436"
     data-ad-slot="6647210859"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script>

<!-- <script type="text/javascript" src="//pagead2.googlesyndication.com/pagead/show_ads.js"></script> -->


<!-- /Google AdSense -->

		</div>




		<div class="reklambox reklambox-top reklambox-top-full" id="reklambox-top-right">		<!-- Ad block TOP RIGHT box -->
			<a class="envato-box" href="https://elements.envato.com/?utm_source=media-buying&utm_medium=banner-mb&utm_campaign=elements_mb_paletton.com&utm_content=120x654_home"></a> 
		</div>



	<!-- Ad block RIGHT column -->

		<div class="reklambox" id="reklambox-col-right">

<!-- Google AdSense -->
<script type="text/javascript">

	$('#reklambox-col-right').hide();
//	$('#reklambox-top-right').hide();

</script>
<!--
<script type="text/javascript" src="//pagead2.googlesyndication.com/pagead/show_ads.js"></script>
-->


<!-- /Google AdSense -->

		</div>


		<div class="reklambox" id="reklambox-bottom">

<script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
<!-- Paletton - 728x15 text -->
<ins class="adsbygoogle"
     style="display:inline-block;width:728px;height:15px"
     data-ad-client="ca-pub-0771264873734436"
     data-ad-slot="6586678057"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script>

			<div id="adblock-info">
				This is just a hobby project, but it requires investments to keep it alive and improve. Displaying advertisement is the only profit this site provides. Please consider NOT using ad-blocking software on this site. Or, if you prefer to, you can donate using the link on the right. Thanks for supporting our project.
			</div>


<script type="text/javascript">
if (!browserInfo.adBlockActive) {
	var e = document.getElementById('adblock-info');
	if (e) e.remove();
	}
</script>

			<div class="donate">
				<form action="https://www.paypal.com/cgi-bin/webscr" method="post" target="_top">
				<input type="hidden" name="cmd" value="_s-xclick">
				<input type="hidden" name="hosted_button_id" value="FG9B4ZLTT4E9Y">
				<input type="image" src="https://www.paypalobjects.com/en_US/i/btn/btn_donate_SM.gif" border="0" name="submit" alt="PayPal - The safer, easier way to pay online!">
				<img alt="" border="0" src="https://www.paypalobjects.com/en_US/i/scr/pixel.gif" width="1" height="1">
				</form>
			</div>


<!-- 			Related:  -->

<!-- webydo -->
<!--
			<span class="spot">
				<a href="http://dashboard.webydo.com/landingpages/starta.aspx?campaign=colorschemedesigner&utm_source=colorschemedesigne&utm_medium=cpc&utm_content=footer-link&utm_campaign=paletton" rel="nofollow">Design CODE-FREE Websites</a>
			</span>
-->
<!-- // -->

<!-- Wix -->
<!--
			<span class="spot">
				<a href="http://www.wix.com/eteamhtml/templates-us?utm_campaign=ma_paletton.com&experiment_id=ma_paletton.com_TLFWT_templates-us">Free Website Templates</a>
			</span>
			<span class="spot">
				<a href="http://www.wix.com/eteamhtml/900flip?utm_campaign=ma_paletton.com&experiment_id=ma_paletton.com_TLCYW_900flip">Create Your Website</a>
			</span>
-->

<!-- // -->

		</div>


	</div> <!-- /app -->


<!-- Google Analytics -->

<script type="text/javascript">
	(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
	(i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
	m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
	})(window,document,'script','//www.google-analytics.com/analytics.js','ga');
	ga('create', 'UA-1465350-8', 'paletton.com' , {'name': 'old'});
	ga('old.require', 'displayfeatures');
	ga('old.send', 'pageview');
	ga('create', 'UA-51179325-1', 'paletton.com');
	ga('require', 'displayfeatures');
</script>

<!-- /Google Analytics -->


</body>
</html>
