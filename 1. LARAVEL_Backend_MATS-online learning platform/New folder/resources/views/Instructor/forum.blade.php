@extends('layouts.instructorlayout')
@section('content')


<center>
<h2>Forum</h2>
<br>
    <div style="width:800px;  text-align:left; padding:20; background-color:rgb(189, 189, 189)">
    <h4>New Post</h4>
        <form class="form-floating" action="{{route('instructor.forumsubmit')}}" method="post">
        {{@csrf_field()}}
    
            <input type="hidden" name="u_id" value="{{Session::get('userid')}}" >
            
            <input type="text" name="ins_name" style=" border:0px; color: rgb(199, 0, 0); font-size: 25px; " value="{{$instructor->ins_name}}"  disabled>
            <br>

            
                <select name="c_id" id="c_id">
                    <option value="none" selected disabled hidden>Select a course</option>
                    @foreach ($instructor->coursesbyinstructor as $c)
                        @if($c->c_status != "Inactive")
                        <option value="{{$c->id}}">{{$c->c_title}}</option>
                        @endif
                    @endforeach
                    
                </select>
                <br>


            <textarea name="f_question" placeholder="Write something.." rows="3" cols="50">{{old('f_question')}}</textarea>
            @error('f_question')
            <span>{{$message}}</span>
            @enderror
            <br>
    
        
    
            <input class="btn btn-secondary" type="submit" value="Post">
        </form>


</div>

<br><br>

<div style="width:800px;  text-align:left; padding:20; background-color:rgb(131, 131, 131)">
    <h4>Posts:</h4>
 @foreach($forum as $f)
    
        <br><br>
        @if(($f->course->c_instructor_fk) == $instructor->id)
        <div style="width:750px; border-radius:15px;  text-align:left; padding:20; background-color:rgb(209, 209, 209)">
            <h5 style="font-size: 9">{{date('F j,Y g:ia',strtotime($f->f_datetime))}}</h5>
            <h4 style="font-size: 16">{{$f->users->u_username."/".$f->users->u_name}}</h4>
            <h5 style="font-size: 12"> {{$f->course->c_title}}</h5>
            <p style="margin-left:10px; font-size: 15; font-family:Verdana, Geneva, Tahoma, sans-serif; font-style:italic">{{$f->f_question}}</p>
     

            
                               
                    <div>
                        <form class="form-floating" action="{{route('instructor.forumcommentsubmit')}}" method="post">
                            {{@csrf_field()}}

                                <input type="hidden" name="u_id" value="{{Session::get('userid')}}" >
                               
                                <input type="hidden" name="fc_forum_fk" value="{{$f->id}}" >
                              
                    
                                <textarea name="fc_comment" placeholder="Leave a comment.." rows="2" cols="60">{{old('fc_comment')}}</textarea>
                                @error('fc_comment')
                                <span>{{$message}}</span>
                                @enderror
                                <br>
                        
                            
                        
                                <input class="btn btn-secondary" type="submit" value="Comment">
                            </form>
                    
                    
                    </div>
                    
                
                         @foreach($forumcomments as $fc)
                    
                            @if(($fc->fc_forum_fk) == $f->id)
                            
                            <div style="width:400px; border-radius:15px; border:0.3px solid rgb(247, 247, 247); text-align:left; padding:20; background-color:rgb(230, 230, 230)">
                                <h5 style="font-size: 9">{{date('F j,Y g:ia',strtotime($fc->fc_datetime))}}</h5>
                                <h4 style="font-size: 16">{{$fc->users->u_username."/".$fc->users->u_name}}</h4>
                                <h5 style="font-size: 12">{{$fc->forum->course->c_title}}</h5>
                                <p style="margin-left:10px; font-size: 15; font-family:Verdana, Geneva, Tahoma, sans-serif; font-style:italic">{{$fc->fc_comment}}</p>
                            
                            </div>
                            @endif 
                        @endforeach 
                    
                
                </div>
        @endif
    
 @endforeach
</div>
</center>


@endsection