/*   
 * this is an arduino class object
 */
function Arduino(config) {
	
	_url = config.url;
	_div = config.div;
	
	var colors = [
		{
			value: "red",
			url: _url + "?color="
		},
		{
			value: "orange",
			url: _url + "?color="
		},
		{
			value: "yellow",
			url: _url + "?color="
		},
		{
			value: "green",
			url: _url + "?color="
		},
		{
			value: "blue",
			url: _url + "?color="
		}
	];
	
	// private function
	function init() {
		
		// anything you want to initialize with the object itself
		
	}
	
	/* private function 
	 * makeRequest()
	 * Makes an ajax request
	 */
	function makeRequest() {
		
		$.ajax({
			url		: "arduinourl",
			type	: "GET",
			dataType: "html",
			//dataType: "jsonp",
			success : function(data) {
				// this is your call back - what do you want to happen AFTER the data is there?
				
			},
			failure : function(data) {
				
			}	
		});
	}
	
	/* privledged function 
	 * getColorURL(color)
	 * has access to both privledged and private functions 
	 * must be initalized in order to use
	 */
	this.getColorURL(color) {
		
		// recursive for loop that looks through each object
		$(colors).each(function(index){
			// get each object
			if(color == this.color)
				return this.url;		
		});
	}
	
	// initialize the object
	init();
}

/* Public Function 
 * thisIsPublic
 * Can do something w/ the object w/o initializing a new version
 * does not have access to neitehr privledged nor private
 */
Arduino.prototype.thisIsPublic = function() {
	// you can access this w/o initializing a new object
	
	
}