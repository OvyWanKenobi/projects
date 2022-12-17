

<nav class="navbar navbar-expand-sm bg-black bg-opacity-75 navbar-dark fixed-top" style=" height: 70px;">
    <div class="container-fluid">

        <ul class="navbar-nav">
          <li class="nav-item">
            <a class="nav-link " href="{{route('instructor.home')}}">Home</a>
          </li>
         <li class="nav-item">
            <a class="nav-link" href="{{route('instructor.createcourse')}}">Create Course</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="{{route('instructor.forum')}}">Forum</a>
          </li>
          <li class="nav-item"><a class="nav-link" href="{{route('instructor.financial')}}">Financial</a></li>
        
        </ul>
    
    <div class="nav navbar-right ">
  
    
        <ul class="navbar-nav ">
          <li class="nav-item" >
            <a class="nav-link" href="{{route('instructor.profile')}}">
                @if ((Session::get('userdp'))==Null)
                <img  src="{{asset('storage/nodpimage.png')}}"  style=" object-fit:cover; width:50px; height:50px; border-radius:50%;"  alt="Image">
                 @else
                 <img  src="{{asset('storage/dp/instructors/'.Session::get('userdp'))}}"  style="width:50px; height:50px; border-radius:50%; "  alt="Image">
                 @endif
                 {{Session::get('nameuser')}}
                 </a> 
          </li>


          <li class="nav-item">
            <a class=" btn btn-danger" style="margin-top:10px;" href="{{route('Logout')}}">Logout</a>
          </li>
          
        </ul>
    </div>
</div>

</nav>


<br><br>
<br><br>

