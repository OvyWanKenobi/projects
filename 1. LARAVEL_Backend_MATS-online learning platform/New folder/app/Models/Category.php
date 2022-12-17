<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use App\Models\Instructor;

class Category extends Model
{
    use HasFactory;

    protected $table = 'categories';
    public $timestamps = false;

    public function instructors(){
        return $this->hasMany(Instructor::class, 'ins_cat_fk');
    }
}
