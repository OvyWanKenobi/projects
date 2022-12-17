using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace travelwhims.Auth
{
    public class AgencyAccess : AuthorizeAttribute
    {
        protected override bool AuthorizeCore(HttpContextBase httpContext)
        {
            var authenticated = base.AuthorizeCore(httpContext);
            if(!authenticated) { 
                return false; 
            }

           if(httpContext.Session["UserType"].ToString().Equals("agency")  ){
                return true;
            }
            return false;
        }
    }
}