/*	JAVASCRIPT DOCUMENT
*	UTF-8
*/

/*  pro-rpico-modbus-rtu
*   webSCADA client / UI controller
*   AT09 (atgroup09@gmail.com), 2023
*
*   The JavaScript code in this page is free software: you can
*   redistribute it and/or modify it under the terms of the GNU
*   General Public License (GNU GPL) as published by the Free Software
*   Foundation, either version 3 of the License, or (at your option)
*   any later version.  The code is distributed WITHOUT ANY WARRANTY;
*   without even the implied warranty of MERCHANTABILITY or FITNESS
*   FOR A PARTICULAR PURPOSE.  See the GNU GPL for more details.
*
*   As additional permission under GNU GPL version 3 section 7, you
*   may distribute non-source (e.g., minimized or compacted) forms of
*   that code without the copy of the GNU GPL normally required by
*   section 4, provided you include this license notice and a URL
*   through which recipients can access the Corresponding Source.
*/

/** Dependencies:
 *    + mod/hmi-v3.js.js
 *    + mod/ui-hmi-v3.js
 *    + mod/ui-hmi-v3.css
 */

//WebHMI-server configuration
var G_WS_SERVER_URI 	= "ws://127.0.0.1:8100";
var G_WS_SERVER_ID  	= "pro-rpico-modbus-rtu";
var G_WS_SERVER_NET_ID 	= 1;
var G_WS_SERVER_DEV_ID 	= 1;

//* forms
var G_FORM_LED_CMD    = null;
var G_FORM_USER_16BIT = null;


/*
@brief  Handler for event FormViewScheme.onClicked
@param  event - Event-object.	[OBJECT]
@return None.
*/
function onFormViewSchemeClicked(event)
{
	var Res = G_FORM_SET.getResultset();

	if(Res)
	{
		var Status = ((typeof Res["scheme_use"] == "number") ? true : false);
		var Node   = $("#RootCase");
		Node.toggle(Status);
	}
}

/*
@brief  Handler for event LED_CMD_apply.onClicked
@param  event - Event-object.	[OBJECT]
@return None.
*/
function onLedCmdApplyClicked(event)
{
	if(hasWsServerOpened())
	{
		var Res = G_FORM_LED_CMD.getResultset();
		
		if(Res)
		{
			var Msg = {SrvID:G_WS_SERVER_ID, NetID:G_WS_SERVER_NET_ID, DevID:G_WS_SERVER_DEV_ID, Data:Res, Stamp:(new Date()).get_current_time_stamp()};
			//console.log(Msg);
			//convert message object into JSON-string and send it to WsServer
			sendToWsServer(JSON.stringify(Msg));
		}
	}
}

/*
@brief  Handler for event USER_16BIT_apply.onClicked
@param  event - Event-object.	[OBJECT]
@return None.
*/
function onUser16bitApplyClicked(event)
{
	if(hasWsServerOpened())
	{
		var Res = G_FORM_USER_16BIT.getResultset();
		
		if(Res)
		{
			var Msg = {SrvID:G_WS_SERVER_ID, NetID:G_WS_SERVER_NET_ID, DevID:G_WS_SERVER_DEV_ID, Data:Res, Stamp:(new Date()).get_current_time_stamp()};
			//console.log(Msg);
			//convert message object into JSON-string and send it to WsServer
			sendToWsServer(JSON.stringify(Msg));
		}
	}
}

/*
@brief  Function: Initialize forms
@param  None.
@return None.
*/
function initForms()
{
	if(typeof jsForm == "function")
	{
		G_FORM_LED_CMD = new jsForm("LED_CMD_form");
		G_FORM_LED_CMD["ItemOptions"] = { LED_CMD: { ItemType: "select", DataType: "number", Allow: true } };
		$("#LED_CMD_apply").bind("click", onLedCmdApplyClicked);
		G_FORM_LED_CMD.AutoCreate = true;
		
		G_FORM_USER_16BIT = new jsForm("USER_16BIT_form");
		G_FORM_USER_16BIT["ItemOptions"] = { USER_16BIT: { ItemType: "number", DataType: "number", Allow: true } };
		$("#USER_16BIT_apply").bind("click", onUser16bitApplyClicked);
		G_FORM_USER_16BIT.AutoCreate = true;
	}
}

/*
@brief  Inititialize UI.
@param  None.
@return None.
*/
function Main_InitUI()
{
	if(typeof initUI == "function")
	{
        /* INIT WS-HMI
         */
		
		//Settings of tags (link data with WebHMI-content)
		//* _txt - Text
		//* _bil - BitLamp
		//* _plo - Plot/Chart
		var WsOpts = { LED_STATUS_bil: { DataKey:"LED_STATUS", setNode:"LED_STATUS_bil", NodeAlg:"BitLamp", toBoolNum:true, byRiseEdge:true },
						  LED_CMD_txt: { DataKey:"LED_CMD", setNode:"LED_CMD_txt", NodeAlg:"Text", toBoolNum:true },
		                     TEMP_txt: { DataKey:"TEMP", setNode:"TEMP_txt", NodeAlg:"Text", round:2 },
					   USER_16BIT_txt: { DataKey:"USER_16BIT", setNode:"USER_16BIT_txt", NodeAlg:"Text" }
							 
				     };
		
		//Init. WebHMI-client
		initUI(G_WS_SERVER_URI, G_WS_SERVER_ID, WsOpts);


        /* INIT UI
         */
		
		G_FORM_SET["ItemOptions"]["scheme_use"]	= { ItemType: "checkbox", DataType: "number", Allow: true };
		$("#FormViewScheme").bind("click", onFormViewSchemeClicked);
		
		initForms();
	}
}
