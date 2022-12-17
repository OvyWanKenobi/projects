//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace travelwhims.Models.TWdatabase
{
    using System;
    using System.Collections.Generic;
    
    public partial class CustomerPackage
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public CustomerPackage()
        {
            this.Payments = new HashSet<Payment>();
            this.Ratings = new HashSet<Rating>();
        }
    
        public int id { get; set; }
        public int pac_id { get; set; }
        public int cus_id { get; set; }
        public int ta_id { get; set; }
        public Nullable<int> pay_discount { get; set; }
        public string pay_status { get; set; }
    
        public virtual Customer Customer { get; set; }
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<Payment> Payments { get; set; }
        public virtual TravelAgency TravelAgency { get; set; }
        public virtual Package Package { get; set; }
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<Rating> Ratings { get; set; }
    }
}
