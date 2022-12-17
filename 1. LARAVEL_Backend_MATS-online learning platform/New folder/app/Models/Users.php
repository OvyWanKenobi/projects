<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Users extends Model
{
    use HasFactory;
    protected $table = 'userlogins';
    public $timestamps = false;

    public function forum(){
        return $this->hasMany(Forum::class, 'st_id');
    }

    public function forumcomment(){
        return $this->belongsTo(Forumcomments::class, 'fc_uid');
    }

}
